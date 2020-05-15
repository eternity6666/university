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
        for (int i = 0; i < numOfPoints; i++) {// 初始化节点
            nodes[i] = new Node();
            nodes[i].serialNum = i;
        }
        for (int i = 0; i < numOfSides; i++) {// 解析输入路径的信息
            int x = scanner.nextInt(), y = scanner.nextInt();
            nodes[x].neighbors.add(nodes[y]);
            nodes[y].neighbors.add(nodes[x]);
        }
        getNeighbor(nodes[new Random().nextInt(nodes.length)], null);// 随便取一个点开始遍历
        for (Node node : nodes) {
            System.out.println(node.isPoint);
        }
        System.out.println(points.size());
    }

    public static Node getNeighbor(Node node, Node fatherNode) {// 如果有其他返回路径则返回false，否则返回true
        if (pathStack.contains(node))
            return node;// 在路径栈中则返回该节点
        pathStack.push(node);// 该节点不在路径栈中则入栈后继续深度优先遍历
        ArrayList<Node> findAnswer = new ArrayList<>();
        int numOfSubTree = 0;
        for (Node neighbor : node.neighbors) {
            if (!Objects.equals(neighbor.isPoint, null) || Objects.equals(neighbor, fatherNode))
                continue;// 已知是一个关节点或者是父节点则跳过搜索
            numOfSubTree++;// 是未确定的邻居则子树的数量加一
            // 这个邻居可能不是关节点,则需要搜索该节点
            Node searchResult = getNeighbor(neighbor, node);
            if (searchResult != null)
                findAnswer.add(searchResult);// 把这个邻居连接到的最老祖先加入集合。
        }
        pathStack.pop();// 遍历完该节点的邻居了，弹出该节点
        if (numOfSubTree == 0) {// 没有子树,则返回连接到的最老祖先，如果是一个终结点则会返回null
            node.isPoint = false;
            return putOldest(findAnswer);
        }
        if (numOfSubTree == 1) {// 有唯一子树
            if (fatherNode == null) {// 特殊情况，这个节点是起始节点，则这个节点其实是一个终结点
                node.isPoint = false;
                return null;
            }
            Node oldestNode = putOldest(findAnswer);
            if (oldestNode == null) {// 没有返回路径
                node.isPoint = true;// 这个节点是一个关节点
                points.add(node);
            } else
                node.isPoint = false;// 子树有返回路径则，这个节点不是一个关节点
            return oldestNode;// 返回子树路径
        } // 这个节点有多于一棵的子树
        node.isPoint = true;// 这个节点是一个关节点
        points.add(node);
        return putOldest(findAnswer);
    }

    static Node putOldest(ArrayList<Node> results) {
        if (results.size() == 0)// 这个子树没有返回路径
            return null;
        int numOldest = pathStack.size();
        for (Node result : results) {// 找到连接到的最老祖先
            int numSearch = pathStack.indexOf(result);
            if (numSearch < numOldest && numSearch != -1)
                numOldest = numSearch;
        }
        if (numOldest == pathStack.size())
            return null;// 这些连接都是回到该节点的，返回null
        else
            return pathStack.get(numOldest);// 有返回路径则返回最老祖先
    }
}