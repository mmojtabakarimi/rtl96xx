<html>
<head>
<meta http-equiv="Pragma" content="no-cache">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" href="style.css" type="text/css">
<title></title>
<SCRIPT language=JavaScript src=utils.js></SCRIPT>
<SCRIPT language=JavaScript src=spec.js></SCRIPT>
<SCRIPT language=JavaScript src=valid.js></SCRIPT>
<script language=JavaScript>

pageTitle();

var webVars = new Array( <% CGI_GET_WEB_CONST(); %>);
var sysip = new Array(<% CGI_SYS_IP(); %>);
//var sysip = new Array('CLT502;00:11:22:33:44:55;static',
//'ok;192.168.0.100;255.255.255.0;192.168.0.1;202.96.125.24;34.45.25.14;0.0.0.0',
//'doing;0.0.0.0;0.0.0.0;0.0.0.0;202.96.125.24;34.45.25.14;0.0.0.0;86400;local'
//);

function get_ip_proto()
{
	if (sysip.length > 0){
		var vs = sysip[0].split(';');
		if (vs.length > 2) return vs[2];
	}
	return 'static';
}

function get_hostname()
{
	if (sysip.length > 0){
		var vs = sysip[0].split(';');
		if (vs.length > 0) return vs[0];
	}
	return 'N/A';
}

function get_dhcp_status()
{
	if (sysip.length > 2){
		var vs = sysip[2].split(';');
		if (vs.length > 0) {
			if (vs[0] == 'stop') return "Stop";				
			if (vs[0] == 'doing') return "Fetching...";	
			if (vs[0] == 'failed') return "Failed";
			if (vs[0] == 'ok') return "Success";			
		}
	}
	return 'N/A';
}

function get_dhcp_lease()
{
	if (sysip.length > 2){
		var vs = sysip[2].split(';');
		if (vs.length > 7) return vs[7];		
	}
	return 'N/A';
}

function get_ip(type)
{
	var item = (type == 'static') ? 1 : 2;
	if (sysip.length > item){
		var vs = sysip[item].split(';');
		if (vs.length > 1) return vs[1];		
	}
	return '0.0.0.0';
}

function get_nm(type)
{
	var item = (type == 'static') ? 1 : 2;
	if (sysip.length > item){
		var vs = sysip[item].split(';');
		if (vs.length > 2) return vs[2];		
	}
	return '0.0.0.0';
}

function get_gw(type)
{
	var item = (type == 'static') ? 1 : 2;
	if (sysip.length > item){
		var vs = sysip[item].split(';');
		if (vs.length > 3) return vs[3];		
	}
	return '0.0.0.0';
}

function get_dns(type, i)
{
	var item = (type == 'static') ? 1 : 2;
	if (sysip.length > item){
		var vs = sysip[item].split(';');
		if (vs.length > (4 + i)) return vs[4 + i];		
	}
	return '0.0.0.0';
}

function ip_set(form_in, val)
{
	form_in[0].value = val.split('.')[0];
	form_in[1].value = val.split('.')[1];
	form_in[2].value = val.split('.')[2];	
	form_in[3].value = val.split('.')[3];
}

function ip_get(form_in)
{
	return form_in[0].value + '.' + form_in[1].value + '.' + form_in[2].value + '.' + form_in[3].value;
}

function dhcp_renew()
{
	
}

function dhcp_release()
{
	
}


function valid_ip_items(IP)
{
	if (IP.length != 4) return false;
  var re = /^\d*$/;
  for (var i = 0; i < 4; i ++){
		if (!re.test(IP[i].value)){
				return false;	
		}	
  }
  return true;
}

function f2ip(IP)
{
	return IP[0].value + '.' +	IP[1].value + '.' + IP[2].value + '.'  + IP[3].value;
}

function valid_ip(ip)
{
	var ips = ip.split('.');
	for (var i = 0; i < 4; i ++){
		if (parseInt(ips[i]) > 255) return false;	
	}
	var a0 = parseInt(ips[0]);
	if ((a0 == 0) || (a0 == 127) || (a0 > 223)){
		return false;	
	}
	return true;
	}
	
function valid_ip_or_zero(ip)
{
	var zero = 1;
	var ips = ip.split('.');
	for (var i = 0; i < 4; i ++){
		if (parseInt(ips[i]) > 255) return false;	
		if (parseInt(ips[i]) != 0 ){
			zero = 0;	
		}
	}
	if (zero) return true;
	
	var a0 = parseInt(ips[0]);
	if ((a0 == 0) || (a0 == 127) || (a0 > 223)){
		return false;	
	}
	return true;
}

function valid_netmask(nm){
    var re = /(254|252|248|240|224|192|128)\.0\.0\.0|255\.(254|252|248|240|224|192|128|0)\.0\.0|255\.255\.(254|252|248|240|224|192|128|0)\.0|255\.255\.255\.(254|252|248|240|224|192|128|0)/;
    if (!re.test(nm))
    {
        return false;
    }
    return true;
}


function valid_gateway(ip, nm, gw)
{
	
	if (!valid_ip_or_zero(gw)){
		return false;
	}
	var ips = ip.split('.');
	var ipv = (parseInt(ips[0],10)<<24)|(parseInt(ips[1],10)<<16)|(parseInt(ips[2])<<8)|parseInt(ips[3]);
 	var nms = nm.split('.');
	var nmv = (parseInt(nms[0],10)<<24)|(parseInt(nms[1],10)<<16)|(parseInt(nms[2],10)<<8)|parseInt(nms[3],10);
	var gws = gw.split('.');
	var gwv = (parseInt(gws[0],10)<<24)|(parseInt(gws[1],10)<<16)|(parseInt(gws[2])<<8)|parseInt(gws[3]);
		
	if ((ipv | nmv) == (gwv | nmv)) 
		return false; 
	else 
		return true;
}


function ip_proto_on_change()
{
	var	f = document.forms[0];
	var str = '';
	if(f.PROTO.value == 'static') {
		str += '<table width=100% border=0 align=center cellpadding=5 cellspacing=1	bgcolor="#FFFFFF">';
		str += '<tr>';
		str += '<td class=bgblue>IP Address</td>';
		str += '<td class=bggrey><input name=IP size=3 maxlength=3>. ';
		str += '<input name=IP size=3 maxlength=3>. <input name=IP size=3 maxlength=3>. <input name=IP size=3 maxlength=3>';
		str += '</td></tr><tr>';
		str += '<td class=bgblue>Subnet Mask</td>';
		str += '<td class=bggrey><input name=NM size=3 maxlength=3>. <input ';
		str += 'name=NM size=3 maxlength=3>. <input name=NM size=3 ';
		str += 'maxlength=3>. <input name=NM size=3 maxlength=3></td>';
		str += '</tr><tr><td class=bgblue>Default Gateway</td>';
		str += '<td class=bggrey><input name=GW size=3 maxlength=3>. <input ';
		str += 'name=GW size=3 maxlength=3>. <input name=GW size=3 ';
		str += 'maxlength=3>. <input name=GW size=3 maxlength=3></td></tr>';
		str += '</table>';
		document.getElementById('static_ip').innerHTML = str;	
	  ip_set(f.IP, get_ip('static'));
		ip_set(f.NM, get_nm('static'));
		ip_set(f.GW, get_gw('static'));
		ip_set(f.DNS1, get_dns('static', 0));
		ip_set(f.DNS2, get_dns('static', 1));
	}
	else {
		str += '<table width=100% border=0 align=center cellpadding=5 cellspacing=1	bgcolor="#FFFFFF">';
		str += '<tr>';
		str += '<td class=bgblue>DHCP State</td>';
		str += '<td class=bggrey>' + get_dhcp_status() + '</td>';
		str += '<td class=bggrey width=35% align=center><input name="dhr" type=button value="Update" onclick=apply_all("renew");>';
		str += '&nbsp;&nbsp;&nbsp;&nbsp;<input name="dhr" type=button value="Release" onclick=apply_all("none"); disabled=true></td>';
		str += '</tr>';
		str += '<tr><td class=bgblue>IP Address</td>';
		str += '<td class=bggrey colspan=2>' + get_ip('dhcp');
		str += '</td></tr><tr>';
		str += '<td class=bgblue>Subnet Mask</td>';
		str += '<td class=bggrey colspan=2>' + get_nm('dhcp');
		str += '</td></tr>';
		str += '<tr><td class=bgblue>Default Gateway</td>';
		str += '<td class=bggrey colspan=2>' + get_gw('dhcp');;
		str += '</td></tr>';
		str += '<tr><td class=bgblue>Lease Duration</td>';
		str += '<td class=bggrey colspan=2>' + get_dhcp_lease(); + ' Sec';
		str += '</td></tr>';
		str += '</table>';
		document.getElementById('static_ip').innerHTML = str;
		ip_set(f.DNS1, get_dns('dhcp', 0));
		ip_set(f.DNS2, get_dns('dhcp', 1));
	}
}

function init()
{
	var f=document.forms[0];
	f.PROTO.value = get_ip_proto();
	f.HN.value = get_hostname();
	ip_proto_on_change();
}

function check_all_input()
{
	var f = document.forms[0];
	if (!valid_host(f.HN.value)){
		alert("Invaid Hostname '" + f.HN.value + "'");	
		return false;
	}
	
	if(f.PROTO.value == 'static') {
			if (!valid_ip_items(f.IP) || !valid_ip(f2ip(f.IP))){
				 alert("Invalid IP Address, please input again!");	
				 return false;
			}
			if (!valid_ip_items(f.NM)  || !valid_netmask(f2ip(f.NM)) ){
				 alert("Invalid IP Subnet Mask, please input again!");	
				 return false;
			}
			if (!valid_ip_items(f.GW) || !valid_gateway(f2ip(f.IP), f2ip(f.NM), f2ip(f.GW))){
				 alert("Invalid Gateway Address, please input again!");	
				 return false;
			}
	}
	if (!valid_ip_items(f.DNS1) || !valid_ip_or_zero(f2ip(f.DNS1))){
		 alert("Invalid DNS Server Address, please input again!");	
		 return false;
	}
	if (!valid_ip_items(f.DNS2) || !valid_ip_or_zero(f2ip(f.DNS2))){
		 alert("Invalid DNS Server Address, please input again!");	
		 return false;
	}	
  return true;
}
function apply_all(dhcp_action)
{
	var newip = 0;
	var nextpage, proto ;
	var f=document.forms[0];
	
	if (!check_all_input())return;
	if (f.PROTO.value != get_ip_proto()){
		if (f.PROTO.value == 'static'){
			newip = ip_get(f.IP);	
		}else {
			dhcp_action = "renew";
			//newip = get_ip('static');	
		}
		
	}else if (f.PROTO.value == 'static'){
		if ((ip_get(f.IP) != get_ip('static')) || (ip_get(f.NM) != get_nm('static'))){
			newip = ip_get(f.IP);
		}
	}
	
	// set all config
	diffCfg("PROTO", "ip_proto", f.PROTO.value);
	diffCfg("HN", "hostname", f.HN.value);
			
	if (f.PROTO.value == 'static'){
		diffCfg("IP", "sys_ip", ip_get(f.IP));
		diffCfg("NM", "sys_nm", ip_get(f.NM));
		diffCfg("GW", "sys_gw", ip_get(f.GW));
	}else {
		diffCfg("IP", "sys_ip", "0.0.0.0");
		diffCfg("NM", "sys_nm", "0.0.0.0");
		diffCfg("GW", "sys_gw", "0.0.0.0");		
	}
	diffCfg("DNS1", "sys_dns", ip_get(f.DNS1));
	diffCfg("DNS2", "sys_dns", ip_get(f.DNS2));	
	diffCfg("DHCP0", "dhcp_action", dhcp_action);
	
	nextpage = newip ? 'http://' + newip + '/index.asp' : 'system_man_ip.asp';		
	subForm(f,'goform/command','SYS_MANIP', nextpage);
}


</script>
</head>

<body onload=init()>
<script>pageHead(webVars);</script>
<form name=system_man_ip action=goform/command method=post>

<table width=100% border=0 align=center cellpadding=0 cellspacing=0
	class=box_tn>
	<tr>
		<td>
		<table width=100% border=0 align=center cellpadding=5 cellspacing=1	bgcolor="#FFFFFF">
			<tr>
				<td class=bgblue>Link Mode</td>
				<td class=bggrey>
					<select name="PROTO" onchange="ip_proto_on_change();">
					<option value='static'>Static</option>
					<option value='dhcp'>DHCP Server</option>
					</select>
				</td>
			</tr>
			<tr>
				<td class=bgblue>Hostname</td>
				<td class=bggrey><input name=HN size=31 maxlength=31></td>
			</tr>
		</table>
		<div id="static_ip"></div>
		<table width=100% border=0 align=center cellpadding=5 cellspacing=1	bgcolor="#FFFFFF">
			<tr>
				<td class=bgblue>DNS Server</td>
				<td class=bggrey><input name=DNS1 size=3 maxlength=3>. <input
					name=DNS1 size=3 maxlength=3>. <input name=DNS1 size=3
					maxlength=3>. <input name=DNS1 size=3 maxlength=3></td>
			</tr>
			<tr>
				<td class=bgblue>Alternative DNS Server</td>
				<td class=bggrey><input name=DNS2 size=3 maxlength=3>. <input
					name=DNS2 size=3 maxlength=3>. <input name=DNS2 size=3
					maxlength=3>. <input name=DNS2 size=3 maxlength=3></td>
			</tr>
		</table>
		</td>
	</tr>
</table>
<p>
<input type=button value="  OK  " onclick=apply_all("none") >
<input type=button value="Cancel" onclick=init() >
</p>
</form>

<script>pageTail();</script>
</body>
</html>
