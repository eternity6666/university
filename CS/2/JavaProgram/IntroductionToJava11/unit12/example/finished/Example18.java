// WebCrawler.java

package unit12.example.out;

import java.util.Scanner;
import java.util.ArrayList;

public class Example18 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a URL: ");
        String url = input.nextLine();
        crawler(url);
    }

    public static void crawler(String startingURL) {
        ArrayList<String> listOfPendingURLs = new ArrayList<>();
        ArrayList<String> listOfTraversedURLs = new ArrayList<>();

        listOfPendingURLs.add(startingURL);
        while(!listOfPendingURLs.isEmpty() && listOfTraversedURLs.size() <= 10000) {
            String urlString = listOfPendingURLs.remove(0);
            if(!listOfTraversedURLs.contains(urlString)) {
                listOfTraversedURLs.add(urlString);
                System.out.println("Crawl " + urlString);

                for (String s: getSubURLs(urlString)) {
                    if(!listOfTraversedURLs.contains(s))
                        listOfPendingURLs.add(s);
                }
            }
        }
    }

    public static ArrayList<String> getSubURLs(String urlString) {
        ArrayList<String> list = new ArrayList<>();

        try {
            java.net.URL url = new java.net.URL(urlString);
            Scanner input = new Scanner(url.openStream());
            int current = 0;
            int currents = 0;
            while(input.hasNext()) {
                String line = input.nextLine();
                current = line.indexOf("https:", current);
                while(current > 0) {
                    int endIndex = line.indexOf("\"", current);
                    if(endIndex > 0) {
                        list.add(line.substring(current, endIndex));
                        // System.out.println(line.substring(current, endIndex));
                        current = line.indexOf("https:", endIndex);
                    }
                    else
                        current = -1;
                }
            }
        }
        catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        }

        return list;
    }
}


