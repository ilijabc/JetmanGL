



<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link rel="icon" type="image/vnd.microsoft.icon" href="http://www.gstatic.com/codesite/ph/images/phosting.ico">
 
 
 <script type="text/javascript">
 
 (function(){var a=function(b){this.t={};this.tick=function(b,c,d){c=void 0!=d?d:(new Date).getTime();this.t[b]=c};this.tick("start",null,b)},e=new a;window.jstiming={Timer:a,load:e};try{var f=null;window.chrome&&window.chrome.csi&&(f=Math.floor(window.chrome.csi().pageT));null==f&&window.gtbExternal&&(f=window.gtbExternal.pageT());null==f&&window.external&&(f=window.external.pageT);f&&(window.jstiming.pt=f)}catch(g){};})();

 
 
 
 
 var codesite_token = null;
 
 
 var CS_env = {"profileUrl":null,"token":null,"assetHostPath":"http://www.gstatic.com/codesite/ph","domainName":null,"assetVersionPath":"http://www.gstatic.com/codesite/ph/5121560014714628542","projectHomeUrl":"/p/poly2tri","relativeBaseUrl":"","projectName":"poly2tri","loggedInUserEmail":null};
 var _gaq = _gaq || [];
 _gaq.push(
 ['siteTracker._setAccount', 'UA-18071-1'],
 ['siteTracker._trackPageview']);
 
 (function() {
 var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
 ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
 (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(ga);
 })();
 
 </script>
 
 
 <title>shapes.h - 
 poly2tri -
 
 
 A 2D constrained Delaunay triangulation library - Google Project Hosting
 </title>
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/5121560014714628542/css/core.css">
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/5121560014714628542/css/ph_detail.css" >
 
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/5121560014714628542/css/d_sb.css" >
 
 
 
<!--[if IE]>
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/5121560014714628542/css/d_ie.css" >
<![endif]-->
 <style type="text/css">
 .menuIcon.off { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -42px }
 .menuIcon.on { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -28px }
 .menuIcon.down { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 0; }
 
 
 
  tr.inline_comment {
 background: #fff;
 vertical-align: top;
 }
 div.draft, div.published {
 padding: .3em;
 border: 1px solid #999; 
 margin-bottom: .1em;
 font-family: arial, sans-serif;
 max-width: 60em;
 }
 div.draft {
 background: #ffa;
 } 
 div.published {
 background: #e5ecf9;
 }
 div.published .body, div.draft .body {
 padding: .5em .1em .1em .1em;
 max-width: 60em;
 white-space: pre-wrap;
 white-space: -moz-pre-wrap;
 white-space: -pre-wrap;
 white-space: -o-pre-wrap;
 word-wrap: break-word;
 font-size: 1em;
 }
 div.draft .actions {
 margin-left: 1em;
 font-size: 90%;
 }
 div.draft form {
 padding: .5em .5em .5em 0;
 }
 div.draft textarea, div.published textarea {
 width: 95%;
 height: 10em;
 font-family: arial, sans-serif;
 margin-bottom: .5em;
 }

 
 .nocursor, .nocursor td, .cursor_hidden, .cursor_hidden td {
 background-color: white;
 height: 2px;
 }
 .cursor, .cursor td {
 background-color: darkblue;
 height: 2px;
 display: '';
 }
 
 
.list {
 border: 1px solid white;
 border-bottom: 0;
}

 
 </style>
</head>
<body class="t4">
<script type="text/javascript">
 window.___gcfg = {lang: 'en'};
 (function() 
 {var po = document.createElement("script");
 po.type = "text/javascript"; po.async = true;po.src = "https://apis.google.com/js/plusone.js";
 var s = document.getElementsByTagName("script")[0];
 s.parentNode.insertBefore(po, s);
 })();
</script>
<div class="headbg">

 <div id="gaia">
 

 <span>
 
 
 <a href="#" id="projects-dropdown" onclick="return false;"><u>My favorites</u> <small>&#9660;</small></a>
 | <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=http%3A%2F%2Fcode.google.com%2Fp%2Fpoly2tri%2Fsource%2Fbrowse%2Fpoly2tri%2Fcommon%2Fshapes.h&amp;followup=http%3A%2F%2Fcode.google.com%2Fp%2Fpoly2tri%2Fsource%2Fbrowse%2Fpoly2tri%2Fcommon%2Fshapes.h" onclick="_CS_click('/gb/ph/signin');"><u>Sign in</u></a>
 
 </span>

 </div>

 <div class="gbh" style="left: 0pt;"></div>
 <div class="gbh" style="right: 0pt;"></div>
 
 
 <div style="height: 1px"></div>
<!--[if lte IE 7]>
<div style="text-align:center;">
Your version of Internet Explorer is not supported. Try a browser that
contributes to open source, such as <a href="http://www.firefox.com">Firefox</a>,
<a href="http://www.google.com/chrome">Google Chrome</a>, or
<a href="http://code.google.com/chrome/chromeframe/">Google Chrome Frame</a>.
</div>
<![endif]-->



 <table style="padding:0px; margin: 0px 0px 10px 0px; width:100%" cellpadding="0" cellspacing="0"
 itemscope itemtype="http://schema.org/CreativeWork">
 <tr style="height: 58px;">
 
 <td id="plogo">
 <link itemprop="url" href="/p/poly2tri">
 <a href="/p/poly2tri/">
 
 
 <img src="/p/poly2tri/logo?cct=1300302666"
 alt="Logo" itemprop="image">
 
 </a>
 </td>
 
 <td style="padding-left: 0.5em">
 
 <div id="pname">
 <a href="/p/poly2tri/"><span itemprop="name">poly2tri</span></a>
 </div>
 
 <div id="psum">
 <a id="project_summary_link"
 href="/p/poly2tri/"><span itemprop="description">A 2D constrained Delaunay triangulation library</span></a>
 
 </div>
 
 
 </td>
 <td style="white-space:nowrap;text-align:right; vertical-align:bottom;">
 
 <form action="/hosting/search">
 <input size="30" name="q" value="" type="text">
 
 <input type="submit" name="projectsearch" value="Search projects" >
 </form>
 
 </tr>
 </table>

</div>

 
<div id="mt" class="gtb"> 
 <a href="/p/poly2tri/" class="tab ">Project&nbsp;Home</a>
 
 
 
 
 <a href="/p/poly2tri/downloads/list" class="tab ">Downloads</a>
 
 
 
 
 
 <a href="/p/poly2tri/w/list" class="tab ">Wiki</a>
 
 
 
 
 
 <a href="/p/poly2tri/issues/list"
 class="tab ">Issues</a>
 
 
 
 
 
 <a href="/p/poly2tri/source/checkout"
 class="tab active">Source</a>
 
 
 
 
 
 
 
 <div class=gtbc></div>
</div>
<table cellspacing="0" cellpadding="0" width="100%" align="center" border="0" class="st">
 <tr>
 
 
 
 
 
 
 
 <td class="subt">
 <div class="st2">
 <div class="isf">
 
 <form action="/p/poly2tri/source/browse" style="display: inline">
 
 Repository:
 <select name="repo" id="repo" style="font-size: 92%" onchange="submit()">
 <option value="default">default</option><option value="wiki">wiki</option><option value="java">java</option><option value="archive">archive</option><option value="python">python</option><option value="javascript">javascript</option><option value="as3">as3</option><option value="cs">cs</option><option value="golang">golang</option>
 </select>
 </form>
 
 


 <span class="inst1"><a href="/p/poly2tri/source/checkout">Checkout</a></span> &nbsp;
 <span class="inst2"><a href="/p/poly2tri/source/browse/">Browse</a></span> &nbsp;
 <span class="inst3"><a href="/p/poly2tri/source/list">Changes</a></span> &nbsp;
 <span class="inst4"><a href="/p/poly2tri/source/clones">Clones</a></span> &nbsp; 
 &nbsp;
 
 
 <form action="/p/poly2tri/source/search" method="get" style="display:inline"
 onsubmit="document.getElementById('codesearchq').value = document.getElementById('origq').value">
 <input type="hidden" name="q" id="codesearchq" value="">
 <input type="text" maxlength="2048" size="38" id="origq" name="origq" value="" title="Google Code Search" style="font-size:92%">&nbsp;<input type="submit" value="Search Trunk" name="btnG" style="font-size:92%">
 
 
 
 
 
 
 </form>
 <script type="text/javascript">
 
 function codesearchQuery(form) {
 var query = document.getElementById('q').value;
 if (query) { form.action += '%20' + query; }
 }
 </script>
 </div>
</div>

 </td>
 
 
 
 <td align="right" valign="top" class="bevel-right"></td>
 </tr>
</table>


<script type="text/javascript">
 var cancelBubble = false;
 function _go(url) { document.location = url; }
</script>
<div id="maincol"
 
>

 
<!-- IE -->




<div class="expand">
<div id="colcontrol">
<style type="text/css">
 #file_flipper { white-space: nowrap; padding-right: 2em; }
 #file_flipper.hidden { display: none; }
 #file_flipper .pagelink { color: #0000CC; text-decoration: underline; }
 #file_flipper #visiblefiles { padding-left: 0.5em; padding-right: 0.5em; }
</style>
<table id="nav_and_rev" class="list"
 cellpadding="0" cellspacing="0" width="100%">
 <tr>
 
 <td nowrap="nowrap" class="src_crumbs src_nav" width="33%">
 <strong class="src_nav">Source path:&nbsp;</strong>
 <span id="crumb_root">
 
 <a href="/p/poly2tri/source/browse/">hg</a>/&nbsp;</span>
 <span id="crumb_links" class="ifClosed"><a href="/p/poly2tri/source/browse/poly2tri/">poly2tri</a><span class="sp">/&nbsp;</span><a href="/p/poly2tri/source/browse/poly2tri/common/">common</a><span class="sp">/&nbsp;</span>shapes.h</span>
 
 

 </td>
 
 
 <td nowrap="nowrap" width="33%" align="right">
 <table cellpadding="0" cellspacing="0" style="font-size: 100%"><tr>
 
 
 <td class="flipper">
 <ul class="leftside">
 
 <li><a href="/p/poly2tri/source/browse/poly2tri/common/shapes.h?r=122144c456920985c9a5180d162c0be326f5c452" title="Previous">&lsaquo;122144c45692</a></li>
 
 </ul>
 </td>
 
 <td class="flipper"><b>acf81f1f1764</b></td>
 
 </tr></table>
 </td> 
 </tr>
</table>

<div class="fc">
 
 
 
<style type="text/css">
.undermouse span {
 background-image: url(http://www.gstatic.com/codesite/ph/images/comments.gif); }
</style>
<table class="opened" id="review_comment_area"
><tr>
<td id="nums">
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
<pre><table width="100%" id="nums_table_0"><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_1"

><td id="1"><a href="#1">1</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_2"

><td id="2"><a href="#2">2</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_3"

><td id="3"><a href="#3">3</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_4"

><td id="4"><a href="#4">4</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_5"

><td id="5"><a href="#5">5</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_6"

><td id="6"><a href="#6">6</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_7"

><td id="7"><a href="#7">7</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_8"

><td id="8"><a href="#8">8</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_9"

><td id="9"><a href="#9">9</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_10"

><td id="10"><a href="#10">10</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_11"

><td id="11"><a href="#11">11</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_12"

><td id="12"><a href="#12">12</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_13"

><td id="13"><a href="#13">13</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_14"

><td id="14"><a href="#14">14</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_15"

><td id="15"><a href="#15">15</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_16"

><td id="16"><a href="#16">16</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_17"

><td id="17"><a href="#17">17</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_18"

><td id="18"><a href="#18">18</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_19"

><td id="19"><a href="#19">19</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_20"

><td id="20"><a href="#20">20</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_21"

><td id="21"><a href="#21">21</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_22"

><td id="22"><a href="#22">22</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_23"

><td id="23"><a href="#23">23</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_24"

><td id="24"><a href="#24">24</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_25"

><td id="25"><a href="#25">25</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_26"

><td id="26"><a href="#26">26</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_27"

><td id="27"><a href="#27">27</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_28"

><td id="28"><a href="#28">28</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_29"

><td id="29"><a href="#29">29</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_30"

><td id="30"><a href="#30">30</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_31"

><td id="31"><a href="#31">31</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_32"

><td id="32"><a href="#32">32</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_33"

><td id="33"><a href="#33">33</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_34"

><td id="34"><a href="#34">34</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_35"

><td id="35"><a href="#35">35</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_36"

><td id="36"><a href="#36">36</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_37"

><td id="37"><a href="#37">37</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_38"

><td id="38"><a href="#38">38</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_39"

><td id="39"><a href="#39">39</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_40"

><td id="40"><a href="#40">40</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_41"

><td id="41"><a href="#41">41</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_42"

><td id="42"><a href="#42">42</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_43"

><td id="43"><a href="#43">43</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_44"

><td id="44"><a href="#44">44</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_45"

><td id="45"><a href="#45">45</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_46"

><td id="46"><a href="#46">46</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_47"

><td id="47"><a href="#47">47</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_48"

><td id="48"><a href="#48">48</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_49"

><td id="49"><a href="#49">49</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_50"

><td id="50"><a href="#50">50</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_51"

><td id="51"><a href="#51">51</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_52"

><td id="52"><a href="#52">52</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_53"

><td id="53"><a href="#53">53</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_54"

><td id="54"><a href="#54">54</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_55"

><td id="55"><a href="#55">55</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_56"

><td id="56"><a href="#56">56</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_57"

><td id="57"><a href="#57">57</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_58"

><td id="58"><a href="#58">58</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_59"

><td id="59"><a href="#59">59</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_60"

><td id="60"><a href="#60">60</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_61"

><td id="61"><a href="#61">61</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_62"

><td id="62"><a href="#62">62</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_63"

><td id="63"><a href="#63">63</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_64"

><td id="64"><a href="#64">64</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_65"

><td id="65"><a href="#65">65</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_66"

><td id="66"><a href="#66">66</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_67"

><td id="67"><a href="#67">67</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_68"

><td id="68"><a href="#68">68</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_69"

><td id="69"><a href="#69">69</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_70"

><td id="70"><a href="#70">70</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_71"

><td id="71"><a href="#71">71</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_72"

><td id="72"><a href="#72">72</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_73"

><td id="73"><a href="#73">73</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_74"

><td id="74"><a href="#74">74</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_75"

><td id="75"><a href="#75">75</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_76"

><td id="76"><a href="#76">76</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_77"

><td id="77"><a href="#77">77</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_78"

><td id="78"><a href="#78">78</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_79"

><td id="79"><a href="#79">79</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_80"

><td id="80"><a href="#80">80</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_81"

><td id="81"><a href="#81">81</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_82"

><td id="82"><a href="#82">82</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_83"

><td id="83"><a href="#83">83</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_84"

><td id="84"><a href="#84">84</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_85"

><td id="85"><a href="#85">85</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_86"

><td id="86"><a href="#86">86</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_87"

><td id="87"><a href="#87">87</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_88"

><td id="88"><a href="#88">88</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_89"

><td id="89"><a href="#89">89</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_90"

><td id="90"><a href="#90">90</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_91"

><td id="91"><a href="#91">91</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_92"

><td id="92"><a href="#92">92</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_93"

><td id="93"><a href="#93">93</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_94"

><td id="94"><a href="#94">94</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_95"

><td id="95"><a href="#95">95</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_96"

><td id="96"><a href="#96">96</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_97"

><td id="97"><a href="#97">97</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_98"

><td id="98"><a href="#98">98</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_99"

><td id="99"><a href="#99">99</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_100"

><td id="100"><a href="#100">100</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_101"

><td id="101"><a href="#101">101</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_102"

><td id="102"><a href="#102">102</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_103"

><td id="103"><a href="#103">103</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_104"

><td id="104"><a href="#104">104</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_105"

><td id="105"><a href="#105">105</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_106"

><td id="106"><a href="#106">106</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_107"

><td id="107"><a href="#107">107</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_108"

><td id="108"><a href="#108">108</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_109"

><td id="109"><a href="#109">109</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_110"

><td id="110"><a href="#110">110</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_111"

><td id="111"><a href="#111">111</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_112"

><td id="112"><a href="#112">112</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_113"

><td id="113"><a href="#113">113</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_114"

><td id="114"><a href="#114">114</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_115"

><td id="115"><a href="#115">115</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_116"

><td id="116"><a href="#116">116</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_117"

><td id="117"><a href="#117">117</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_118"

><td id="118"><a href="#118">118</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_119"

><td id="119"><a href="#119">119</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_120"

><td id="120"><a href="#120">120</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_121"

><td id="121"><a href="#121">121</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_122"

><td id="122"><a href="#122">122</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_123"

><td id="123"><a href="#123">123</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_124"

><td id="124"><a href="#124">124</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_125"

><td id="125"><a href="#125">125</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_126"

><td id="126"><a href="#126">126</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_127"

><td id="127"><a href="#127">127</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_128"

><td id="128"><a href="#128">128</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_129"

><td id="129"><a href="#129">129</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_130"

><td id="130"><a href="#130">130</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_131"

><td id="131"><a href="#131">131</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_132"

><td id="132"><a href="#132">132</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_133"

><td id="133"><a href="#133">133</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_134"

><td id="134"><a href="#134">134</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_135"

><td id="135"><a href="#135">135</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_136"

><td id="136"><a href="#136">136</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_137"

><td id="137"><a href="#137">137</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_138"

><td id="138"><a href="#138">138</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_139"

><td id="139"><a href="#139">139</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_140"

><td id="140"><a href="#140">140</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_141"

><td id="141"><a href="#141">141</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_142"

><td id="142"><a href="#142">142</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_143"

><td id="143"><a href="#143">143</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_144"

><td id="144"><a href="#144">144</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_145"

><td id="145"><a href="#145">145</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_146"

><td id="146"><a href="#146">146</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_147"

><td id="147"><a href="#147">147</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_148"

><td id="148"><a href="#148">148</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_149"

><td id="149"><a href="#149">149</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_150"

><td id="150"><a href="#150">150</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_151"

><td id="151"><a href="#151">151</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_152"

><td id="152"><a href="#152">152</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_153"

><td id="153"><a href="#153">153</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_154"

><td id="154"><a href="#154">154</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_155"

><td id="155"><a href="#155">155</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_156"

><td id="156"><a href="#156">156</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_157"

><td id="157"><a href="#157">157</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_158"

><td id="158"><a href="#158">158</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_159"

><td id="159"><a href="#159">159</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_160"

><td id="160"><a href="#160">160</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_161"

><td id="161"><a href="#161">161</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_162"

><td id="162"><a href="#162">162</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_163"

><td id="163"><a href="#163">163</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_164"

><td id="164"><a href="#164">164</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_165"

><td id="165"><a href="#165">165</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_166"

><td id="166"><a href="#166">166</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_167"

><td id="167"><a href="#167">167</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_168"

><td id="168"><a href="#168">168</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_169"

><td id="169"><a href="#169">169</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_170"

><td id="170"><a href="#170">170</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_171"

><td id="171"><a href="#171">171</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_172"

><td id="172"><a href="#172">172</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_173"

><td id="173"><a href="#173">173</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_174"

><td id="174"><a href="#174">174</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_175"

><td id="175"><a href="#175">175</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_176"

><td id="176"><a href="#176">176</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_177"

><td id="177"><a href="#177">177</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_178"

><td id="178"><a href="#178">178</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_179"

><td id="179"><a href="#179">179</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_180"

><td id="180"><a href="#180">180</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_181"

><td id="181"><a href="#181">181</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_182"

><td id="182"><a href="#182">182</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_183"

><td id="183"><a href="#183">183</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_184"

><td id="184"><a href="#184">184</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_185"

><td id="185"><a href="#185">185</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_186"

><td id="186"><a href="#186">186</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_187"

><td id="187"><a href="#187">187</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_188"

><td id="188"><a href="#188">188</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_189"

><td id="189"><a href="#189">189</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_190"

><td id="190"><a href="#190">190</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_191"

><td id="191"><a href="#191">191</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_192"

><td id="192"><a href="#192">192</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_193"

><td id="193"><a href="#193">193</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_194"

><td id="194"><a href="#194">194</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_195"

><td id="195"><a href="#195">195</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_196"

><td id="196"><a href="#196">196</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_197"

><td id="197"><a href="#197">197</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_198"

><td id="198"><a href="#198">198</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_199"

><td id="199"><a href="#199">199</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_200"

><td id="200"><a href="#200">200</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_201"

><td id="201"><a href="#201">201</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_202"

><td id="202"><a href="#202">202</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_203"

><td id="203"><a href="#203">203</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_204"

><td id="204"><a href="#204">204</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_205"

><td id="205"><a href="#205">205</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_206"

><td id="206"><a href="#206">206</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_207"

><td id="207"><a href="#207">207</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_208"

><td id="208"><a href="#208">208</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_209"

><td id="209"><a href="#209">209</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_210"

><td id="210"><a href="#210">210</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_211"

><td id="211"><a href="#211">211</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_212"

><td id="212"><a href="#212">212</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_213"

><td id="213"><a href="#213">213</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_214"

><td id="214"><a href="#214">214</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_215"

><td id="215"><a href="#215">215</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_216"

><td id="216"><a href="#216">216</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_217"

><td id="217"><a href="#217">217</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_218"

><td id="218"><a href="#218">218</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_219"

><td id="219"><a href="#219">219</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_220"

><td id="220"><a href="#220">220</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_221"

><td id="221"><a href="#221">221</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_222"

><td id="222"><a href="#222">222</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_223"

><td id="223"><a href="#223">223</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_224"

><td id="224"><a href="#224">224</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_225"

><td id="225"><a href="#225">225</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_226"

><td id="226"><a href="#226">226</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_227"

><td id="227"><a href="#227">227</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_228"

><td id="228"><a href="#228">228</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_229"

><td id="229"><a href="#229">229</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_230"

><td id="230"><a href="#230">230</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_231"

><td id="231"><a href="#231">231</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_232"

><td id="232"><a href="#232">232</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_233"

><td id="233"><a href="#233">233</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_234"

><td id="234"><a href="#234">234</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_235"

><td id="235"><a href="#235">235</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_236"

><td id="236"><a href="#236">236</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_237"

><td id="237"><a href="#237">237</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_238"

><td id="238"><a href="#238">238</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_239"

><td id="239"><a href="#239">239</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_240"

><td id="240"><a href="#240">240</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_241"

><td id="241"><a href="#241">241</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_242"

><td id="242"><a href="#242">242</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_243"

><td id="243"><a href="#243">243</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_244"

><td id="244"><a href="#244">244</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_245"

><td id="245"><a href="#245">245</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_246"

><td id="246"><a href="#246">246</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_247"

><td id="247"><a href="#247">247</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_248"

><td id="248"><a href="#248">248</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_249"

><td id="249"><a href="#249">249</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_250"

><td id="250"><a href="#250">250</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_251"

><td id="251"><a href="#251">251</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_252"

><td id="252"><a href="#252">252</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_253"

><td id="253"><a href="#253">253</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_254"

><td id="254"><a href="#254">254</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_255"

><td id="255"><a href="#255">255</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_256"

><td id="256"><a href="#256">256</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_257"

><td id="257"><a href="#257">257</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_258"

><td id="258"><a href="#258">258</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_259"

><td id="259"><a href="#259">259</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_260"

><td id="260"><a href="#260">260</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_261"

><td id="261"><a href="#261">261</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_262"

><td id="262"><a href="#262">262</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_263"

><td id="263"><a href="#263">263</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_264"

><td id="264"><a href="#264">264</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_265"

><td id="265"><a href="#265">265</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_266"

><td id="266"><a href="#266">266</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_267"

><td id="267"><a href="#267">267</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_268"

><td id="268"><a href="#268">268</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_269"

><td id="269"><a href="#269">269</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_270"

><td id="270"><a href="#270">270</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_271"

><td id="271"><a href="#271">271</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_272"

><td id="272"><a href="#272">272</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_273"

><td id="273"><a href="#273">273</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_274"

><td id="274"><a href="#274">274</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_275"

><td id="275"><a href="#275">275</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_276"

><td id="276"><a href="#276">276</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_277"

><td id="277"><a href="#277">277</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_278"

><td id="278"><a href="#278">278</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_279"

><td id="279"><a href="#279">279</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_280"

><td id="280"><a href="#280">280</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_281"

><td id="281"><a href="#281">281</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_282"

><td id="282"><a href="#282">282</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_283"

><td id="283"><a href="#283">283</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_284"

><td id="284"><a href="#284">284</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_285"

><td id="285"><a href="#285">285</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_286"

><td id="286"><a href="#286">286</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_287"

><td id="287"><a href="#287">287</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_288"

><td id="288"><a href="#288">288</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_289"

><td id="289"><a href="#289">289</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_290"

><td id="290"><a href="#290">290</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_291"

><td id="291"><a href="#291">291</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_292"

><td id="292"><a href="#292">292</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_293"

><td id="293"><a href="#293">293</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_294"

><td id="294"><a href="#294">294</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_295"

><td id="295"><a href="#295">295</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_296"

><td id="296"><a href="#296">296</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_297"

><td id="297"><a href="#297">297</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_298"

><td id="298"><a href="#298">298</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_299"

><td id="299"><a href="#299">299</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_300"

><td id="300"><a href="#300">300</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_301"

><td id="301"><a href="#301">301</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_302"

><td id="302"><a href="#302">302</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_303"

><td id="303"><a href="#303">303</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_304"

><td id="304"><a href="#304">304</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_305"

><td id="305"><a href="#305">305</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_306"

><td id="306"><a href="#306">306</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_307"

><td id="307"><a href="#307">307</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_308"

><td id="308"><a href="#308">308</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_309"

><td id="309"><a href="#309">309</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_310"

><td id="310"><a href="#310">310</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_311"

><td id="311"><a href="#311">311</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_312"

><td id="312"><a href="#312">312</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_313"

><td id="313"><a href="#313">313</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_314"

><td id="314"><a href="#314">314</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_315"

><td id="315"><a href="#315">315</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_316"

><td id="316"><a href="#316">316</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_317"

><td id="317"><a href="#317">317</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_318"

><td id="318"><a href="#318">318</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_319"

><td id="319"><a href="#319">319</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_320"

><td id="320"><a href="#320">320</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_321"

><td id="321"><a href="#321">321</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_322"

><td id="322"><a href="#322">322</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_323"

><td id="323"><a href="#323">323</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_324"

><td id="324"><a href="#324">324</a></td></tr
><tr id="gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_325"

><td id="325"><a href="#325">325</a></td></tr
></table></pre>
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
</td>
<td id="lines">
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
<pre class="prettyprint "><table id="src_table_0"><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_1

><td class="source">/*<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_2

><td class="source"> * Poly2Tri Copyright (c) 2009-2010, Poly2Tri Contributors<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_3

><td class="source"> * http://code.google.com/p/poly2tri/<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_4

><td class="source"> *<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_5

><td class="source"> * All rights reserved.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_6

><td class="source"> *<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_7

><td class="source"> * Redistribution and use in source and binary forms, with or without modification,<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_8

><td class="source"> * are permitted provided that the following conditions are met:<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_9

><td class="source"> *<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_10

><td class="source"> * * Redistributions of source code must retain the above copyright notice,<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_11

><td class="source"> *   this list of conditions and the following disclaimer.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_12

><td class="source"> * * Redistributions in binary form must reproduce the above copyright notice,<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_13

><td class="source"> *   this list of conditions and the following disclaimer in the documentation<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_14

><td class="source"> *   and/or other materials provided with the distribution.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_15

><td class="source"> * * Neither the name of Poly2Tri nor the names of its contributors may be<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_16

><td class="source"> *   used to endorse or promote products derived from this software without specific<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_17

><td class="source"> *   prior written permission.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_18

><td class="source"> *<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_19

><td class="source"> * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_20

><td class="source"> * &quot;AS IS&quot; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_21

><td class="source"> * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_22

><td class="source"> * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_23

><td class="source"> * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_24

><td class="source"> * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_25

><td class="source"> * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_26

><td class="source"> * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_27

><td class="source"> * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_28

><td class="source"> * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_29

><td class="source"> * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_30

><td class="source"> */<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_31

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_32

><td class="source">// Include guard<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_33

><td class="source">#ifndef SHAPES_H<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_34

><td class="source">#define SHAPES_H<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_35

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_36

><td class="source">#include &lt;vector&gt;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_37

><td class="source">#include &lt;cstddef&gt;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_38

><td class="source">#include &lt;assert.h&gt;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_39

><td class="source">#include &lt;cmath&gt;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_40

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_41

><td class="source">namespace p2t {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_42

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_43

><td class="source">struct Edge;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_44

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_45

><td class="source">struct Point {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_46

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_47

><td class="source">  double x, y;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_48

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_49

><td class="source">  /// Default constructor does nothing (for performance).<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_50

><td class="source">  Point()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_51

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_52

><td class="source">    x = 0.0;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_53

><td class="source">    y = 0.0;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_54

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_55

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_56

><td class="source">  /// The edges this point constitutes an upper ending point<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_57

><td class="source">  std::vector&lt;Edge*&gt; edge_list;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_58

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_59

><td class="source">  /// Construct using coordinates.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_60

><td class="source">  Point(double x, double y) : x(x), y(y) {}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_61

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_62

><td class="source">  /// Set this point to all zeros.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_63

><td class="source">  void set_zero()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_64

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_65

><td class="source">    x = 0.0;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_66

><td class="source">    y = 0.0;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_67

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_68

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_69

><td class="source">  /// Set this point to some specified coordinates.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_70

><td class="source">  void set(double x_, double y_)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_71

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_72

><td class="source">    x = x_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_73

><td class="source">    y = y_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_74

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_75

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_76

><td class="source">  /// Negate this point.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_77

><td class="source">  Point operator -() const<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_78

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_79

><td class="source">    Point v;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_80

><td class="source">    v.set(-x, -y);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_81

><td class="source">    return v;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_82

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_83

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_84

><td class="source">  /// Add a point to this point.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_85

><td class="source">  void operator +=(const Point&amp; v)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_86

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_87

><td class="source">    x += v.x;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_88

><td class="source">    y += v.y;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_89

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_90

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_91

><td class="source">  /// Subtract a point from this point.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_92

><td class="source">  void operator -=(const Point&amp; v)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_93

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_94

><td class="source">    x -= v.x;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_95

><td class="source">    y -= v.y;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_96

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_97

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_98

><td class="source">  /// Multiply this point by a scalar.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_99

><td class="source">  void operator *=(double a)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_100

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_101

><td class="source">    x *= a;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_102

><td class="source">    y *= a;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_103

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_104

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_105

><td class="source">  /// Get the length of this point (the norm).<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_106

><td class="source">  double Length() const<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_107

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_108

><td class="source">    return sqrt(x * x + y * y);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_109

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_110

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_111

><td class="source">  /// Convert this point into a unit point. Returns the Length.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_112

><td class="source">  double Normalize()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_113

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_114

><td class="source">    double len = Length();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_115

><td class="source">    x /= len;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_116

><td class="source">    y /= len;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_117

><td class="source">    return len;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_118

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_119

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_120

><td class="source">};<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_121

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_122

><td class="source">// Represents a simple polygon&#39;s edge<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_123

><td class="source">struct Edge {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_124

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_125

><td class="source">  Point* p, *q;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_126

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_127

><td class="source">  /// Constructor<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_128

><td class="source">  Edge(Point&amp; p1, Point&amp; p2) : p(&amp;p1), q(&amp;p2)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_129

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_130

><td class="source">    if (p1.y &gt; p2.y) {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_131

><td class="source">      q = &amp;p1;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_132

><td class="source">      p = &amp;p2;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_133

><td class="source">    } else if (p1.y == p2.y) {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_134

><td class="source">      if (p1.x &gt; p2.x) {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_135

><td class="source">        q = &amp;p1;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_136

><td class="source">        p = &amp;p2;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_137

><td class="source">      } else if (p1.x == p2.x) {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_138

><td class="source">        // Repeat points<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_139

><td class="source">        assert(false);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_140

><td class="source">      }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_141

><td class="source">    }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_142

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_143

><td class="source">    q-&gt;edge_list.push_back(this);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_144

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_145

><td class="source">};<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_146

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_147

><td class="source">// Triangle-based data structures are know to have better performance than quad-edge structures<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_148

><td class="source">// See: J. Shewchuk, &quot;Triangle: Engineering a 2D Quality Mesh Generator and Delaunay Triangulator&quot;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_149

><td class="source">//      &quot;Triangulations in CGAL&quot;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_150

><td class="source">class Triangle {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_151

><td class="source">public:<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_152

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_153

><td class="source">/// Constructor<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_154

><td class="source">Triangle(Point&amp; a, Point&amp; b, Point&amp; c);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_155

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_156

><td class="source">/// Flags to determine if an edge is a Constrained edge<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_157

><td class="source">bool constrained_edge[3];<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_158

><td class="source">/// Flags to determine if an edge is a Delauney edge<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_159

><td class="source">bool delaunay_edge[3];<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_160

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_161

><td class="source">Point* GetPoint(const int&amp; index);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_162

><td class="source">Point* PointCW(Point&amp; point);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_163

><td class="source">Point* PointCCW(Point&amp; point);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_164

><td class="source">Point* OppositePoint(Triangle&amp; t, Point&amp; p);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_165

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_166

><td class="source">Triangle* GetNeighbor(const int&amp; index);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_167

><td class="source">void MarkNeighbor(Point* p1, Point* p2, Triangle* t);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_168

><td class="source">void MarkNeighbor(Triangle&amp; t);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_169

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_170

><td class="source">void MarkConstrainedEdge(const int index);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_171

><td class="source">void MarkConstrainedEdge(Edge&amp; edge);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_172

><td class="source">void MarkConstrainedEdge(Point* p, Point* q);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_173

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_174

><td class="source">int Index(const Point* p);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_175

><td class="source">int EdgeIndex(const Point* p1, const Point* p2);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_176

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_177

><td class="source">Triangle* NeighborCW(Point&amp; point);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_178

><td class="source">Triangle* NeighborCCW(Point&amp; point);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_179

><td class="source">bool GetConstrainedEdgeCCW(Point&amp; p);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_180

><td class="source">bool GetConstrainedEdgeCW(Point&amp; p);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_181

><td class="source">void SetConstrainedEdgeCCW(Point&amp; p, bool ce);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_182

><td class="source">void SetConstrainedEdgeCW(Point&amp; p, bool ce);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_183

><td class="source">bool GetDelunayEdgeCCW(Point&amp; p);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_184

><td class="source">bool GetDelunayEdgeCW(Point&amp; p);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_185

><td class="source">void SetDelunayEdgeCCW(Point&amp; p, bool e);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_186

><td class="source">void SetDelunayEdgeCW(Point&amp; p, bool e);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_187

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_188

><td class="source">bool Contains(Point* p);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_189

><td class="source">bool Contains(const Edge&amp; e);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_190

><td class="source">bool Contains(Point* p, Point* q);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_191

><td class="source">void Legalize(Point&amp; point);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_192

><td class="source">void Legalize(Point&amp; opoint, Point&amp; npoint);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_193

><td class="source">/**<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_194

><td class="source"> * Clears all references to all other triangles and points<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_195

><td class="source"> */<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_196

><td class="source">void Clear();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_197

><td class="source">void ClearNeighbor(Triangle *triangle );<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_198

><td class="source">void ClearNeighbors();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_199

><td class="source">void ClearDelunayEdges();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_200

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_201

><td class="source">inline bool IsInterior();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_202

><td class="source">inline void IsInterior(bool b);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_203

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_204

><td class="source">Triangle&amp; NeighborAcross(Point&amp; opoint);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_205

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_206

><td class="source">void DebugPrint();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_207

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_208

><td class="source">private:<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_209

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_210

><td class="source">/// Triangle points<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_211

><td class="source">Point* points_[3];<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_212

><td class="source">/// Neighbor list<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_213

><td class="source">Triangle* neighbors_[3];<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_214

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_215

><td class="source">/// Has this triangle been marked as an interior triangle?<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_216

><td class="source">bool interior_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_217

><td class="source">};<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_218

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_219

><td class="source">inline bool cmp(const Point* a, const Point* b)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_220

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_221

><td class="source">  if (a-&gt;y &lt; b-&gt;y) {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_222

><td class="source">    return true;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_223

><td class="source">  } else if (a-&gt;y == b-&gt;y) {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_224

><td class="source">    // Make sure q is point with greater x value<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_225

><td class="source">    if (a-&gt;x &lt; b-&gt;x) {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_226

><td class="source">      return true;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_227

><td class="source">    }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_228

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_229

><td class="source">  return false;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_230

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_231

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_232

><td class="source">/// Add two points_ component-wise.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_233

><td class="source">inline Point operator +(const Point&amp; a, const Point&amp; b)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_234

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_235

><td class="source">  return Point(a.x + b.x, a.y + b.y);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_236

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_237

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_238

><td class="source">/// Subtract two points_ component-wise.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_239

><td class="source">inline Point operator -(const Point&amp; a, const Point&amp; b)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_240

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_241

><td class="source">  return Point(a.x - b.x, a.y - b.y);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_242

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_243

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_244

><td class="source">/// Multiply point by scalar<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_245

><td class="source">inline Point operator *(double s, const Point&amp; a)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_246

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_247

><td class="source">  return Point(s * a.x, s * a.y);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_248

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_249

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_250

><td class="source">inline bool operator ==(const Point&amp; a, const Point&amp; b)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_251

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_252

><td class="source">  return a.x == b.x &amp;&amp; a.y == b.y;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_253

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_254

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_255

><td class="source">inline bool operator !=(const Point&amp; a, const Point&amp; b)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_256

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_257

><td class="source">  return a.x != b.x &amp;&amp; a.y != b.y;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_258

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_259

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_260

><td class="source">/// Peform the dot product on two vectors.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_261

><td class="source">inline double Dot(const Point&amp; a, const Point&amp; b)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_262

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_263

><td class="source">  return a.x * b.x + a.y * b.y;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_264

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_265

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_266

><td class="source">/// Perform the cross product on two vectors. In 2D this produces a scalar.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_267

><td class="source">inline double Cross(const Point&amp; a, const Point&amp; b)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_268

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_269

><td class="source">  return a.x * b.y - a.y * b.x;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_270

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_271

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_272

><td class="source">/// Perform the cross product on a point and a scalar. In 2D this produces<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_273

><td class="source">/// a point.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_274

><td class="source">inline Point Cross(const Point&amp; a, double s)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_275

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_276

><td class="source">  return Point(s * a.y, -s * a.x);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_277

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_278

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_279

><td class="source">/// Perform the cross product on a scalar and a point. In 2D this produces<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_280

><td class="source">/// a point.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_281

><td class="source">inline Point Cross(const double s, const Point&amp; a)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_282

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_283

><td class="source">  return Point(-s * a.y, s * a.x);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_284

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_285

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_286

><td class="source">inline Point* Triangle::GetPoint(const int&amp; index)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_287

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_288

><td class="source">  return points_[index];<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_289

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_290

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_291

><td class="source">inline Triangle* Triangle::GetNeighbor(const int&amp; index)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_292

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_293

><td class="source">  return neighbors_[index];<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_294

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_295

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_296

><td class="source">inline bool Triangle::Contains(Point* p)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_297

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_298

><td class="source">  return p == points_[0] || p == points_[1] || p == points_[2];<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_299

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_300

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_301

><td class="source">inline bool Triangle::Contains(const Edge&amp; e)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_302

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_303

><td class="source">  return Contains(e.p) &amp;&amp; Contains(e.q);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_304

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_305

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_306

><td class="source">inline bool Triangle::Contains(Point* p, Point* q)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_307

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_308

><td class="source">  return Contains(p) &amp;&amp; Contains(q);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_309

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_310

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_311

><td class="source">inline bool Triangle::IsInterior()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_312

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_313

><td class="source">  return interior_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_314

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_315

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_316

><td class="source">inline void Triangle::IsInterior(bool b)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_317

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_318

><td class="source">  interior_ = b;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_319

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_320

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_321

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_322

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_323

><td class="source">#endif<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_324

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_325

><td class="source"><br></td></tr
></table></pre>
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
</td>
</tr></table>

 
<script type="text/javascript">
 var lineNumUnderMouse = -1;
 
 function gutterOver(num) {
 gutterOut();
 var newTR = document.getElementById('gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_' + num);
 if (newTR) {
 newTR.className = 'undermouse';
 }
 lineNumUnderMouse = num;
 }
 function gutterOut() {
 if (lineNumUnderMouse != -1) {
 var oldTR = document.getElementById(
 'gr_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_' + lineNumUnderMouse);
 if (oldTR) {
 oldTR.className = '';
 }
 lineNumUnderMouse = -1;
 }
 }
 var numsGenState = {table_base_id: 'nums_table_'};
 var srcGenState = {table_base_id: 'src_table_'};
 var alignerRunning = false;
 var startOver = false;
 function setLineNumberHeights() {
 if (alignerRunning) {
 startOver = true;
 return;
 }
 numsGenState.chunk_id = 0;
 numsGenState.table = document.getElementById('nums_table_0');
 numsGenState.row_num = 0;
 if (!numsGenState.table) {
 return; // Silently exit if no file is present.
 }
 srcGenState.chunk_id = 0;
 srcGenState.table = document.getElementById('src_table_0');
 srcGenState.row_num = 0;
 alignerRunning = true;
 continueToSetLineNumberHeights();
 }
 function rowGenerator(genState) {
 if (genState.row_num < genState.table.rows.length) {
 var currentRow = genState.table.rows[genState.row_num];
 genState.row_num++;
 return currentRow;
 }
 var newTable = document.getElementById(
 genState.table_base_id + (genState.chunk_id + 1));
 if (newTable) {
 genState.chunk_id++;
 genState.row_num = 0;
 genState.table = newTable;
 return genState.table.rows[0];
 }
 return null;
 }
 var MAX_ROWS_PER_PASS = 1000;
 function continueToSetLineNumberHeights() {
 var rowsInThisPass = 0;
 var numRow = 1;
 var srcRow = 1;
 while (numRow && srcRow && rowsInThisPass < MAX_ROWS_PER_PASS) {
 numRow = rowGenerator(numsGenState);
 srcRow = rowGenerator(srcGenState);
 rowsInThisPass++;
 if (numRow && srcRow) {
 if (numRow.offsetHeight != srcRow.offsetHeight) {
 numRow.firstChild.style.height = srcRow.offsetHeight + 'px';
 }
 }
 }
 if (rowsInThisPass >= MAX_ROWS_PER_PASS) {
 setTimeout(continueToSetLineNumberHeights, 10);
 } else {
 alignerRunning = false;
 if (startOver) {
 startOver = false;
 setTimeout(setLineNumberHeights, 500);
 }
 }
 }
 function initLineNumberHeights() {
 // Do 2 complete passes, because there can be races
 // between this code and prettify.
 startOver = true;
 setTimeout(setLineNumberHeights, 250);
 window.onresize = setLineNumberHeights;
 }
 initLineNumberHeights();
</script>

 
 
 <div id="log">
 <div style="text-align:right">
 <a class="ifCollapse" href="#" onclick="_toggleMeta(this); return false">Show details</a>
 <a class="ifExpand" href="#" onclick="_toggleMeta(this); return false">Hide details</a>
 </div>
 <div class="ifExpand">
 
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="changelog">
 <p>Change log</p>
 <div>
 <a href="/p/poly2tri/source/detail?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&amp;r=51065c2decbce03b9cb31be0003566a37dd57edf">51065c2decbc</a>
 by zzzzrrr &lt;mason.green&gt;
 on Mar 8, 2011
 &nbsp; <a href="/p/poly2tri/source/diff?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=51065c2decbce03b9cb31be0003566a37dd57edf&amp;format=side&amp;path=/poly2tri/common/shapes.h&amp;old_path=/poly2tri/common/shapes.h&amp;old=122144c456920985c9a5180d162c0be326f5c452">Diff</a>
 </div>
 <pre>updated waf</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/poly2tri/source/detail?r=51065c2decbce03b9cb31be0003566a37dd57edf&spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7';
 var publish_url = '/p/poly2tri/source/detail?r=51065c2decbce03b9cb31be0003566a37dd57edf&spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/poly2tri/common/shapes.cc');
 changed_urls.push('/p/poly2tri/source/browse/poly2tri/common/shapes.cc?r\x3d51065c2decbce03b9cb31be0003566a37dd57edf\x26spec\x3dsvnacf81f1f17647fe9574e3ae8f7a1731ee11085c7');
 
 
 changed_paths.push('/poly2tri/common/shapes.h');
 changed_urls.push('/p/poly2tri/source/browse/poly2tri/common/shapes.h?r\x3d51065c2decbce03b9cb31be0003566a37dd57edf\x26spec\x3dsvnacf81f1f17647fe9574e3ae8f7a1731ee11085c7');
 
 var selected_path = '/poly2tri/common/shapes.h';
 
 
 changed_paths.push('/waf');
 changed_urls.push('/p/poly2tri/source/browse/waf?r\x3d51065c2decbce03b9cb31be0003566a37dd57edf\x26spec\x3dsvnacf81f1f17647fe9574e3ae8f7a1731ee11085c7');
 
 
 changed_paths.push('/wscript');
 changed_urls.push('/p/poly2tri/source/browse/wscript?r\x3d51065c2decbce03b9cb31be0003566a37dd57edf\x26spec\x3dsvnacf81f1f17647fe9574e3ae8f7a1731ee11085c7');
 
 
 function getCurrentPageIndex() {
 for (var i = 0; i < changed_paths.length; i++) {
 if (selected_path == changed_paths[i]) {
 return i;
 }
 }
 }
 function getNextPage() {
 var i = getCurrentPageIndex();
 if (i < changed_paths.length - 1) {
 return changed_urls[i + 1];
 }
 return null;
 }
 function getPreviousPage() {
 var i = getCurrentPageIndex();
 if (i > 0) {
 return changed_urls[i - 1];
 }
 return null;
 }
 function gotoNextPage() {
 var page = getNextPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoPreviousPage() {
 var page = getPreviousPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoDetailPage() {
 window.location = detail_url;
 }
 function gotoPublishPage() {
 window.location = publish_url;
 }
</script>

 
 <style type="text/css">
 #review_nav {
 border-top: 3px solid white;
 padding-top: 6px;
 margin-top: 1em;
 }
 #review_nav td {
 vertical-align: middle;
 }
 #review_nav select {
 margin: .5em 0;
 }
 </style>
 <div id="review_nav">
 <table><tr><td>Go to:&nbsp;</td><td>
 <select name="files_in_rev" onchange="window.location=this.value">
 
 <option value="/p/poly2tri/source/browse/poly2tri/common/shapes.cc?r=51065c2decbce03b9cb31be0003566a37dd57edf&amp;spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7"
 
 >/poly2tri/common/shapes.cc</option>
 
 <option value="/p/poly2tri/source/browse/poly2tri/common/shapes.h?r=51065c2decbce03b9cb31be0003566a37dd57edf&amp;spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7"
 selected="selected"
 >/poly2tri/common/shapes.h</option>
 
 <option value="/p/poly2tri/source/browse/waf?r=51065c2decbce03b9cb31be0003566a37dd57edf&amp;spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7"
 
 >/waf</option>
 
 <option value="/p/poly2tri/source/browse/wscript?r=51065c2decbce03b9cb31be0003566a37dd57edf&amp;spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7"
 
 >/wscript</option>
 
 </select>
 </td></tr></table>
 
 
 



 <div style="white-space:nowrap">
 Project members,
 <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=http%3A%2F%2Fcode.google.com%2Fp%2Fpoly2tri%2Fsource%2Fbrowse%2Fpoly2tri%2Fcommon%2Fshapes.h&amp;followup=http%3A%2F%2Fcode.google.com%2Fp%2Fpoly2tri%2Fsource%2Fbrowse%2Fpoly2tri%2Fcommon%2Fshapes.h"
 >sign in</a> to write a code review</div>


 
 </div>
 
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="older_bubble">
 <p>Older revisions</p>
 
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/poly2tri/source/detail?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=122144c456920985c9a5180d162c0be326f5c452">122144c45692</a>
 by zzzzrrr &lt;mason.green&gt;
 on Jan 19, 2011
 &nbsp; <a href="/p/poly2tri/source/diff?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=122144c456920985c9a5180d162c0be326f5c452&amp;format=side&amp;path=/poly2tri/common/shapes.h&amp;old_path=/poly2tri/common/shapes.h&amp;old=e501f94b9adc60ff188f0a446436f6e19bfc0eb4">Diff</a>
 <br>
 <pre class="ifOpened">fixed Point::set_zero()</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/poly2tri/source/detail?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=e501f94b9adc60ff188f0a446436f6e19bfc0eb4">e501f94b9adc</a>
 by zzzz...@zzzzrrr-laptop
 on Apr 25, 2010
 &nbsp; <a href="/p/poly2tri/source/diff?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=e501f94b9adc60ff188f0a446436f6e19bfc0eb4&amp;format=side&amp;path=/poly2tri/common/shapes.h&amp;old_path=/poly2tri/common/shapes.h&amp;old=4c1c134a6366c112fca302ecdf89d7aa5fdda759">Diff</a>
 <br>
 <pre class="ifOpened">memory cleanup</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/poly2tri/source/detail?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=4c1c134a6366c112fca302ecdf89d7aa5fdda759">4c1c134a6366</a>
 by zzzzrrr &lt;mason.green&gt;
 on Jan 22, 2010
 &nbsp; <a href="/p/poly2tri/source/diff?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=4c1c134a6366c112fca302ecdf89d7aa5fdda759&amp;format=side&amp;path=/poly2tri/common/shapes.h&amp;old_path=/poly2tri/common/shapes.h&amp;old=6fb490cff060ff4af8f5b2f2b082896780cd039f">Diff</a>
 <br>
 <pre class="ifOpened">added p2t namespace</pre>
 </div>
 
 
 <a href="/p/poly2tri/source/list?path=/poly2tri/common/shapes.h&r=51065c2decbce03b9cb31be0003566a37dd57edf">All revisions of this file</a>
 </div>
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="fileinfo_bubble">
 <p>File info</p>
 
 <div>Size: 7456 bytes,
 325 lines</div>
 
 <div><a href="//poly2tri.googlecode.com/hg/poly2tri/common/shapes.h">View raw file</a></div>
 </div>
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 </div>
 </div>


</div>

</div>
</div>

<script src="http://www.gstatic.com/codesite/ph/5121560014714628542/js/prettify/prettify.js"></script>
<script type="text/javascript">prettyPrint();</script>


<script src="http://www.gstatic.com/codesite/ph/5121560014714628542/js/source_file_scripts.js"></script>

 <script type="text/javascript" src="http://www.gstatic.com/codesite/ph/5121560014714628542/js/kibbles.js"></script>
 <script type="text/javascript">
 var lastStop = null;
 var initialized = false;
 
 function updateCursor(next, prev) {
 if (prev && prev.element) {
 prev.element.className = 'cursor_stop cursor_hidden';
 }
 if (next && next.element) {
 next.element.className = 'cursor_stop cursor';
 lastStop = next.index;
 }
 }
 
 function pubRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initialized) {
 reloadCursors();
 }
 }
 
 function draftRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initialized) {
 reloadCursors();
 }
 }
 
 function draftDestroyed(data) {
 updateCursorForCell(data.cellId, 'nocursor');
 if (initialized) {
 reloadCursors();
 }
 }
 function reloadCursors() {
 kibbles.skipper.reset();
 loadCursors();
 if (lastStop != null) {
 kibbles.skipper.setCurrentStop(lastStop);
 }
 }
 // possibly the simplest way to insert any newly added comments
 // is to update the class of the corresponding cursor row,
 // then refresh the entire list of rows.
 function updateCursorForCell(cellId, className) {
 var cell = document.getElementById(cellId);
 // we have to go two rows back to find the cursor location
 var row = getPreviousElement(cell.parentNode);
 row.className = className;
 }
 // returns the previous element, ignores text nodes.
 function getPreviousElement(e) {
 var element = e.previousSibling;
 if (element.nodeType == 3) {
 element = element.previousSibling;
 }
 if (element && element.tagName) {
 return element;
 }
 }
 function loadCursors() {
 // register our elements with skipper
 var elements = CR_getElements('*', 'cursor_stop');
 var len = elements.length;
 for (var i = 0; i < len; i++) {
 var element = elements[i]; 
 element.className = 'cursor_stop cursor_hidden';
 kibbles.skipper.append(element);
 }
 }
 function toggleComments() {
 CR_toggleCommentDisplay();
 reloadCursors();
 }
 function keysOnLoadHandler() {
 // setup skipper
 kibbles.skipper.addStopListener(
 kibbles.skipper.LISTENER_TYPE.PRE, updateCursor);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_top', 50);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_bottom', 100);
 // Register our keys
 kibbles.skipper.addFwdKey("n");
 kibbles.skipper.addRevKey("p");
 kibbles.keys.addKeyPressListener(
 'u', function() { window.location = detail_url; });
 kibbles.keys.addKeyPressListener(
 'r', function() { window.location = detail_url + '#publish'; });
 
 kibbles.keys.addKeyPressListener('j', gotoNextPage);
 kibbles.keys.addKeyPressListener('k', gotoPreviousPage);
 
 
 }
 </script>
<script src="http://www.gstatic.com/codesite/ph/5121560014714628542/js/code_review_scripts.js"></script>
<script type="text/javascript">
 function showPublishInstructions() {
 var element = document.getElementById('review_instr');
 if (element) {
 element.className = 'opened';
 }
 }
 var codereviews;
 function revsOnLoadHandler() {
 // register our source container with the commenting code
 var paths = {'svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7': '/poly2tri/common/shapes.h'}
 codereviews = CR_controller.setup(
 {"profileUrl":null,"token":null,"assetHostPath":"http://www.gstatic.com/codesite/ph","domainName":null,"assetVersionPath":"http://www.gstatic.com/codesite/ph/5121560014714628542","projectHomeUrl":"/p/poly2tri","relativeBaseUrl":"","projectName":"poly2tri","loggedInUserEmail":null}, '', 'svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7', paths,
 CR_BrowseIntegrationFactory);
 
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_DRAFT_PLATE, showPublishInstructions);
 
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_PUB_PLATE, pubRevealed);
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_DRAFT_PLATE, draftRevealed);
 codereviews.registerActivityListener(CR_ActivityType.DISCARD_DRAFT_COMMENT, draftDestroyed);
 
 
 
 
 
 
 
 var initialized = true;
 reloadCursors();
 }
 window.onload = function() {keysOnLoadHandler(); revsOnLoadHandler();};

</script>
<script type="text/javascript" src="http://www.gstatic.com/codesite/ph/5121560014714628542/js/dit_scripts.js"></script>

 
 
 
 <script type="text/javascript" src="http://www.gstatic.com/codesite/ph/5121560014714628542/js/ph_core.js"></script>
 
 
 
 
</div> 

<div id="footer" dir="ltr">
 <div class="text">
 <a href="/projecthosting/terms.html">Terms</a> -
 <a href="http://www.google.com/privacy.html">Privacy</a> -
 <a href="/p/support/">Project Hosting Help</a>
 </div>
</div>
 <div class="hostedBy" style="margin-top: -20px;">
 <span style="vertical-align: top;">Powered by <a href="http://code.google.com/projecthosting/">Google Project Hosting</a></span>
 </div>

 
 


 
 
 <script type="text/javascript">_CS_reportToCsi();</script>
 
 </body>
</html>

