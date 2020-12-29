public class Info {
    private String m_url = "";
    private String m_protocol = "";
    private String m_domain = "";
    private String m_path = "";
    private String m_params = "";

    private int m_depth = 0;

    public Info() {

    }

    public Info(String url) {
        setUrl(url);
    }

    public Info(String url, int depth) {
        setUrl(url);
        m_depth = depth;
    }

    public void setUrl(String url) {
        m_url = url;
        splitUrl();
    }

    public String getUrl() {
        return m_url;
    }

    public void setDepth(int depth) {
        m_depth = depth;
    }

    public int getDepth() {
        return m_depth;
    }

    public String getProtocol() {
        return m_protocol;
    }

    public String getDomain() {
        return m_domain;
    }

    public String getPath() {
        return m_path;
    }

    public String getParams() {
        return m_params;
    }

    protected void splitUrl() {
        String[] domain = m_url.split("://", 2);
        m_protocol = domain[0] + "://";

        String[] path = domain[1].split("/", 2);
        m_domain = path[0];

        m_path = "/";
        if (path.length > 1) {
            String[] params = path[1].split("\\?");
            m_path += params[0];
            if (params.length > 1) {
                m_params = "?" + params[1];
            }
        }
    }
}