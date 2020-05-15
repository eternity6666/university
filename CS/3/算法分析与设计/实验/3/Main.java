import java.util.*;

public class Main {
    static ArrayList<Node> points = new ArrayList<>();
    static Node[] nodes;
    static Stack<Node> pathStack = new Stack<>();

    static class Node {
        int serialNum;
        ArrayList<Node> neighbors = new ArrayList<>();
        Boolean isPoint = null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numOfPoints = scanner.nextInt();
        int numOfSides = scanner.nextInt();
        nodes = new Node[numOfPoints];
        for (int i = 0; i < numOfPoints; i++) {// ��ʼ���ڵ�
            nodes[i] = new Node();
            nodes[i].serialNum = i;
        }
        for (int i = 0; i < numOfSides; i++) {// ��������·������Ϣ
            int x = scanner.nextInt(), y = scanner.nextInt();
            nodes[x].neighbors.add(nodes[y]);
            nodes[y].neighbors.add(nodes[x]);
        }
        getNeighbor(nodes[new Random().nextInt(nodes.length)], null);// ���ȡһ���㿪ʼ����
        for (Node node : nodes) {
            System.out.println(node.isPoint);
        }
        System.out.println(points.size());
    }

    public static Node getNeighbor(Node node, Node fatherNode) {// �������������·���򷵻�false�����򷵻�true
        if (pathStack.contains(node))
            return node;// ��·��ջ���򷵻ظýڵ�
        pathStack.push(node);// �ýڵ㲻��·��ջ������ջ�����������ȱ���
        ArrayList<Node> findAnswer = new ArrayList<>();
        int numOfSubTree = 0;
        for (Node neighbor : node.neighbors) {
            if (!Objects.equals(neighbor.isPoint, null) || Objects.equals(neighbor, fatherNode))
                continue;// ��֪��һ���ؽڵ�����Ǹ��ڵ�����������
            numOfSubTree++;// ��δȷ�����ھ���������������һ
            // ����ھӿ��ܲ��ǹؽڵ�,����Ҫ�����ýڵ�
            Node searchResult = getNeighbor(neighbor, node);
            if (searchResult != null)
                findAnswer.add(searchResult);// ������ھ����ӵ����������ȼ��뼯�ϡ�
        }
        pathStack.pop();// ������ýڵ���ھ��ˣ������ýڵ�
        if (numOfSubTree == 0) {// û������,�򷵻����ӵ����������ȣ������һ���ս����᷵��null
            node.isPoint = false;
            return putOldest(findAnswer);
        }
        if (numOfSubTree == 1) {// ��Ψһ����
            if (fatherNode == null) {// �������������ڵ�����ʼ�ڵ㣬������ڵ���ʵ��һ���ս��
                node.isPoint = false;
                return null;
            }
            Node oldestNode = putOldest(findAnswer);
            if (oldestNode == null) {// û�з���·��
                node.isPoint = true;// ����ڵ���һ���ؽڵ�
                points.add(node);
            } else
                node.isPoint = false;// �����з���·��������ڵ㲻��һ���ؽڵ�
            return oldestNode;// ��������·��
        } // ����ڵ��ж���һ�õ�����
        node.isPoint = true;// ����ڵ���һ���ؽڵ�
        points.add(node);
        return putOldest(findAnswer);
    }

    static Node putOldest(ArrayList<Node> results) {
        if (results.size() == 0)// �������û�з���·��
            return null;
        int numOldest = pathStack.size();
        for (Node result : results) {// �ҵ����ӵ�����������
            int numSearch = pathStack.indexOf(result);
            if (numSearch < numOldest && numSearch != -1)
                numOldest = numSearch;
        }
        if (numOldest == pathStack.size())
            return null;// ��Щ���Ӷ��ǻص��ýڵ�ģ�����null
        else
            return pathStack.get(numOldest);// �з���·���򷵻���������
    }
}