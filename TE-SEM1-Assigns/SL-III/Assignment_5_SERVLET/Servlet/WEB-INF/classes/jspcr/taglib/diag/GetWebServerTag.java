import java.servlet.http.*;
import java.servlet.jsp.*;
import java.servlet.jsp.tagext.*;
import java.io.*;
import java.net.*;

public class GetWebServerTag extends TagSupport
{
	public int doStartTag() throws JspException
	{
	try
	{
		HttpServletRequest request=(HttpServletRequest)pageContext.getRequest();
		URL url=new URL("http",request.getServerName(),request.getServerPort(),"/");
		URLConnection con=url.openConnection();
		((HttpURLConnection) con).setRequestMethod("OPTIONS");
		String WebServer=con.getHeaderField("server");
		JspWriter out=pageContext.getOut();
		out.print(WebServer);
	}
	catch(Exception e)
	{
		throw new JspException(e.getMessage());
	}
	return SKIP_BODY;
}
}
