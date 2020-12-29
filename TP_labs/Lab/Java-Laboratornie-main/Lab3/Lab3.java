import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Hashtable;

public class Lab3 {
    public static void main(String[] args) {
        Cont urlCont = new Cont("https://mtuci.ru");
        int depth = 2;
        int threadNum = 5;

        ArrayList<Scan> scanners = new ArrayList<>(threadNum);
        for (int i = 0; i < threadNum; i++) {
            Scan scanner = new Scan(urlCont, depth);
            scanner.setDaemon(true);
            scanner.start();
            scanners.add(scanner);
        }

        boolean proc = true;
        while (proc == true) {
            Thread.yield();
            proc = false;
            for (Scan scanner : scanners) {
                if (scanner.getState() != Thread.State.WAITING) {
                    proc = true;
                    break;
                }
            }
        }

        Hashtable<String, Info> visitedUrl = urlCont.getVisitedUrl();
        Enumeration<Info> val = visitedUrl.elements();
        while (val.hasMoreElements()) {
            Info urlInfo = val.nextElement();
            System.out.println(urlInfo.getUrl());
        }
        System.out.println("Всего просмотрено url: " + Integer.toString(visitedUrl.size()));
    }
}
