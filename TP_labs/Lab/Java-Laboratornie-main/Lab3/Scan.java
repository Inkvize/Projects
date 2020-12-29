import java.io.*;
import java.net.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Scan extends Thread {
	private final static String PATTERN = "href=\"http://.+?\"";

	private static Cont urlCont;
	private static int m_depthMax = 1;

	public Scan(Cont cont, int depthMax) {
		urlCont = cont;
		m_depthMax = depthMax;
	}
 
	@Override
	public void run() {
		while (true) {
			Info urlInfo = urlCont.getRawUrl();
			scanUrl(urlInfo);
			urlCont.setVisitedUrl(urlInfo);
		}
	}

	public static void scanUrl(Info url) {
		try {
			String ipStr = InetAddress.getByName(url.getDomain()).toString();
			ipStr = ipStr.split("/")[1];
			Socket socket = new Socket(ipStr, 80);
			socket.setSoTimeout(3000);

			PrintWriter prtintWriter = new PrintWriter(socket.getOutputStream());
			prtintWriter.println("GET " + url.getPath() + " HTTP/1.1");
			prtintWriter.println("Host: " + url.getDomain());
			prtintWriter.println("");
			prtintWriter.flush();

			BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String buff = br.readLine();
			if (buff.contains("200")) {
				for (buff = br.readLine(); buff != null && !buff.equals("</html>"); buff = br.readLine()) {
					Pattern patt = Pattern.compile(PATTERN);
					Matcher match = patt.matcher(buff);
					while (match.find()) {
						String htmlUrl = buff.substring(match.start(), match.end());
						int depth = url.getDepth();
						Info urlInfo = new Info(htmlUrl.substring(6, htmlUrl.length() - 1), depth + 1);
						if (depth + 1 <= m_depthMax) {
							urlCont.setRawUrl(urlInfo);
						}
					}
				}
			}
			socket.close();
		} catch (Exception e) {
			System.out.println("Error" + e);
		}
	}
}
