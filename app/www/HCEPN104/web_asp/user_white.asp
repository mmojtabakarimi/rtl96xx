<html>
<head>
<meta http-equiv="Pragma" content="no-cache">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" href="style.css" type="text/css">
<title></title>
<SCRIPT language=JavaScript src=utils.js></SCRIPT>
<SCRIPT language=JavaScript src=spec.js></SCRIPT>
<SCRIPT language=JavaScript src=pageview.js></SCRIPT>
<script language=JavaScript>
pageTitle();

var webVars = new Array( <% CGI_GET_WEB_CONST(); %>);

var supdev = new Array(<% CGI_GET_DEVINFO(); %>);
var tmpl_list = new Array(<% CGI_GET_TEMPLATES("brief"); %>);
var client_list = new Array(<% CGI_GET_USER_CONFIG(); %>);

function acc_string(accs) 
{
	if(accs == 'acc') return '白名单';
	if(accs == 'blk') return '黑名单';
	if(accs == 'any') return '匿名设备';
	return 'N/A';
}

function dev_string(index)
{
	var str = supdev[index].split(';')[0];
	return str;
}

function tmpl_string(tmplid)
{
	return tmpl_list[tmplid].split(';')[2];
}

function user_edit(index)
{
	location='user_edit.asp?action=edit&user_mac=' + client_list[index].split(';')[0];
}

function init()
{
	for(var i = 0; i < client_list.length; i ++) 
		if(client_list[i].split(';')[3] != 'acc') client_list[i] = '';
	pageview_add('MAC地址', 0, '15%', true, null, "user_edit");
	pageview_add('设备型号', 2, '15%', true, dev_string);
	pageview_add('模板', 1, '20%', true, tmpl_string);
	pageview_add('用户名', 4, '15%', true);
	pageview_add('用户描述', 5, '25%', true);
	pageview_init(client_list, 10, document.getElementById('list_table'), false, null, null, '白名单');
}

</script>
</head>
<body onload="init();">
<script>pageHead(webVars);</script>

<form name=system_status action=goform/command method=post>
<INPUT type=hidden name=CMD value=WAN_CON>
<INPUT type=hidden name=GO value=user_list.asp>
<INPUT type=hidden name=action>

<div id="list_table"></div>

</form>

<script>pageTail();</script>
</body>
