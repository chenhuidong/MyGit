<%@ page language="java" import="com.wizardlinux.db.*" %>

  <body>
    This is my JSP page. <br>
      <!-- java 代码 -->
  <%  
  TestMyBatis test=new TestMyBatis();
    out.println("<br> this is server's message : "+test.GetHello());  
   %>
  </body>