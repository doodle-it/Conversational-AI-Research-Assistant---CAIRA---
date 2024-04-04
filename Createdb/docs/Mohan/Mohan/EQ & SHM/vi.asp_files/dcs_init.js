// var gDomain="sdc8dev.wiley.com"; // dev
var gDomain="sdc8prod1.wiley.com";  // prod
var gDcsId="dcs60s2es00000kbemuolm2uf_1n3j";
var gFpc="WT_FPC";
var gConvert=true;

if ((typeof(gConvert)!="undefined")&&gConvert&&(document.cookie.indexOf(gFpc+"=")==-1)&&(document.cookie.indexOf("WTLOPTOUT=")==-1)){
	document.write("<SCR"+"IPT TYPE='text/javascript' SRC='"+"http"+(window.location.protocol.indexOf('https:')==0?'s':'')+"://"+gDomain+"/"+gDcsId+"/wtid.js"+"'><\/SCR"+"IPT>");
}
