<html>
<head>
<meta http-equiv="Pragma" content="no-cache">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" href="style.css" type="text/css">
<title></title>
<SCRIPT language=JavaScript src=utils.js></SCRIPT>
<SCRIPT language=JavaScript src=spec.js></SCRIPT>
<script language=JavaScript>

var webVars = new Array( <% CGI_GET_WEB_CONST(); %>);
var sysinfo = new Array(<% CGI_SYS_INFO(); %>);

addCfg('SWVER','fw_version', sysinfo[2]);
addCfg('HWVER','device_hw_rev', sysinfo[3]);
addCfg('HWADDR','lan_mac_addr', sysinfo[6]);

pageTitle();

function apply()
{
	var f=document.forms[0];
	var file_name=f.uploadfile.value;
	
	if (file_name=="")
    {
		alert("请选择升级文件!");
		return ;
	}
	var len=file_name.toString().length;
	var name_ext=file_name.toString().substring(len-4, len);
	
	if(name_ext != ".bin")
	{
		alert("文件类型错误！");
		return;
	}
    document.getElementById("up_file").value=document.getElementById("uploadfile").value;
	
	if (confirm('系统正在处理升级文件,它需要一些时间,请不要关闭设备电源,并耐心等待!'))
	{			
		f.submit();	
	}
}

</script>
</head>
<body>
<script>pageHead(webVars);</script>

<form name=system_upgrade action=goform/upldForm method=post enctype="multipart/form-data">
<input type=hidden name=TYPE value=UFILE>
<input type=hidden name="up_file" id="up_file">
<table width=100% border=0 align=center cellpadding=5 cellspacing=1 class=box_tn>
<tr>
	<td colspan=2 width=100% class=greybluebg>本地升级</td>
</tr>	
<tr>
	<td width=%20 class=bgblue>
		<b>硬件版本</b>
	</td>
	<td width=%80 class=bggrey>
		<b><script>document.write(getCfg('HWVER'));</script></b>
	</td>
</tr>
<tr>
	<td width=%20 class=bgblue>
		<b>MAC 地址</b>
	</td>
	<td width=%80 class=bggrey>
		<b><script>document.write(getCfg('HWADDR'));</script></b>
	</td>
</tr>
<tr>
	<td width=%20 class=bgblue>
		<b>软件版本</b>
	</td>
	<td width=%80 class=bggrey>
		<b><script>document.write(sysinfo[2]);</script></b>
	</td>
</tr>
<tr>
	<td class=bgblue><b>发布日期</b></td>
	<td class=bggrey>
		<b><script>document.write(sysinfo[7]);</script></b>
	</td>
</tr>
<tr>
	<td class=bgblue><b>软件升级</b></td>
	<td class=bggrey><input type=file size=30 name=uploadfile id="uploadfile"><input type=button value="  确定  " onclick=apply();></td>
</tr>
</table>
</form>

<script>pageTail();</script>
</body>
</html>
