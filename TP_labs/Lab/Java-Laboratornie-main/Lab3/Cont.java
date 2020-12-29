import java.util.*;

public class Cont {
	private Hashtable<String, Info> unprocUrl = new Hashtable<>();
	private Hashtable<String, Info> visitUrl = new Hashtable<>();

	public Cont(String firstUrl) {
		Info urlInf = new Info(firstUrl, 0);
		String key = urlInf.getDomain() + urlInf.getPath() + urlInf.getParams();
		unprocUrl.put(key, urlInf);
	}

	public synchronized Info getRawUrl() {
		System.out.println(unprocUrl.size());
		while (unprocUrl.size() == 0) {
			try {
				wait();
			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
			}
		}

		String key = unprocUrl.keys().nextElement();
		Info urlInf = unprocUrl.get(key);
		unprocUrl.remove(key);

		return urlInf;
	}

	public synchronized void setRawUrl(Info urlInf) {
		String key = urlInf.getDomain() + urlInf.getPath() + urlInf.getParams();
		if (!visitUrl.containsKey(key) && !unprocUrl.containsKey(key)) {
			unprocUrl.put(key, urlInf);
		}
		notify();
	}

	public Hashtable<String, Info> getVisitedUrl() {
		return visitUrl;
	}

	public synchronized void setVisitedUrl(Info urlInf) {
		String key = urlInf.getDomain() + urlInf.getPath() + urlInf.getParams();
		if (!visitUrl.containsKey(key)) {
			visitUrl.put(key, urlInf);
		}
	}
}