



<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link rel="icon" type="image/vnd.microsoft.icon" href="http://www.gstatic.com/codesite/ph/images/phosting.ico">
 
 
 <script type="text/javascript">
 
 
 
 
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
 
 
 <title>sweep_context.h - 
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
 | <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=http%3A%2F%2Fcode.google.com%2Fp%2Fpoly2tri%2Fsource%2Fbrowse%2Fpoly2tri%2Fsweep%2Fsweep_context.h&amp;followup=http%3A%2F%2Fcode.google.com%2Fp%2Fpoly2tri%2Fsource%2Fbrowse%2Fpoly2tri%2Fsweep%2Fsweep_context.h" onclick="_CS_click('/gb/ph/signin');"><u>Sign in</u></a>
 
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
 <span id="crumb_links" class="ifClosed"><a href="/p/poly2tri/source/browse/poly2tri/">poly2tri</a><span class="sp">/&nbsp;</span><a href="/p/poly2tri/source/browse/poly2tri/sweep/">sweep</a><span class="sp">/&nbsp;</span>sweep_context.h</span>
 
 

 </td>
 
 
 <td nowrap="nowrap" width="33%" align="right">
 <table cellpadding="0" cellspacing="0" style="font-size: 100%"><tr>
 
 
 <td class="flipper">
 <ul class="leftside">
 
 <li><a href="/p/poly2tri/source/browse/poly2tri/sweep/sweep_context.h?r=e501f94b9adc60ff188f0a446436f6e19bfc0eb4" title="Previous">&lsaquo;e501f94b9adc</a></li>
 
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

><td class="source">#ifndef SWEEP_CONTEXT_H<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_33

><td class="source">#define SWEEP_CONTEXT_H<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_34

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_35

><td class="source">#include &lt;list&gt;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_36

><td class="source">#include &lt;vector&gt;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_37

><td class="source">#include &lt;cstddef&gt;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_38

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_39

><td class="source">namespace p2t {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_40

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_41

><td class="source">// Inital triangle factor, seed triangle will extend 30% of<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_42

><td class="source">// PointSet width to both left and right.<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_43

><td class="source">const double kAlpha = 0.3;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_44

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_45

><td class="source">struct Point;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_46

><td class="source">class Triangle;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_47

><td class="source">struct Node;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_48

><td class="source">struct Edge;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_49

><td class="source">class AdvancingFront;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_50

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_51

><td class="source">class SweepContext {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_52

><td class="source">public:<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_53

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_54

><td class="source">/// Constructor<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_55

><td class="source">SweepContext(std::vector&lt;Point*&gt; polyline);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_56

><td class="source">/// Destructor<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_57

><td class="source">~SweepContext();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_58

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_59

><td class="source">void set_head(Point* p1);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_60

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_61

><td class="source">Point* head();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_62

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_63

><td class="source">void set_tail(Point* p1);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_64

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_65

><td class="source">Point* tail();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_66

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_67

><td class="source">int point_count();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_68

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_69

><td class="source">Node&amp; LocateNode(Point&amp; point);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_70

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_71

><td class="source">void RemoveNode(Node* node);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_72

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_73

><td class="source">void CreateAdvancingFront(std::vector&lt;Node*&gt; nodes);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_74

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_75

><td class="source">/// Try to map a node to all sides of this triangle that don&#39;t have a neighbor<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_76

><td class="source">void MapTriangleToNodes(Triangle&amp; t);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_77

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_78

><td class="source">void AddToMap(Triangle* triangle);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_79

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_80

><td class="source">Point* GetPoint(const int&amp; index);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_81

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_82

><td class="source">Point* GetPoints();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_83

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_84

><td class="source">void RemoveFromMap(Triangle* triangle);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_85

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_86

><td class="source">void AddHole(std::vector&lt;Point*&gt; polyline);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_87

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_88

><td class="source">void AddPoint(Point* point);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_89

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_90

><td class="source">AdvancingFront* front();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_91

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_92

><td class="source">void MeshClean(Triangle&amp; triangle);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_93

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_94

><td class="source">std::vector&lt;Triangle*&gt; GetTriangles();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_95

><td class="source">std::list&lt;Triangle*&gt; GetMap();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_96

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_97

><td class="source">std::vector&lt;Edge*&gt; edge_list;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_98

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_99

><td class="source">struct Basin {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_100

><td class="source">  Node* left_node;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_101

><td class="source">  Node* bottom_node;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_102

><td class="source">  Node* right_node;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_103

><td class="source">  double width;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_104

><td class="source">  bool left_highest;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_105

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_106

><td class="source">  Basin() : left_node(NULL), bottom_node(NULL), right_node(NULL), width(0.0), left_highest(false)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_107

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_108

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_109

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_110

><td class="source">  void Clear()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_111

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_112

><td class="source">    left_node = NULL;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_113

><td class="source">    bottom_node = NULL;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_114

><td class="source">    right_node = NULL;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_115

><td class="source">    width = 0.0;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_116

><td class="source">    left_highest = false;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_117

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_118

><td class="source">};<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_119

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_120

><td class="source">struct EdgeEvent {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_121

><td class="source">  Edge* constrained_edge;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_122

><td class="source">  bool right;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_123

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_124

><td class="source">  EdgeEvent() : constrained_edge(NULL), right(false)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_125

><td class="source">  {<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_126

><td class="source">  }<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_127

><td class="source">};<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_128

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_129

><td class="source">Basin basin;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_130

><td class="source">EdgeEvent edge_event;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_131

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_132

><td class="source">private:<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_133

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_134

><td class="source">friend class Sweep;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_135

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_136

><td class="source">std::vector&lt;Triangle*&gt; triangles_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_137

><td class="source">std::list&lt;Triangle*&gt; map_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_138

><td class="source">std::vector&lt;Point*&gt; points_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_139

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_140

><td class="source">// Advancing front<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_141

><td class="source">AdvancingFront* front_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_142

><td class="source">// head point used with advancing front<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_143

><td class="source">Point* head_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_144

><td class="source">// tail point used with advancing front<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_145

><td class="source">Point* tail_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_146

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_147

><td class="source">Node *af_head_, *af_middle_, *af_tail_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_148

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_149

><td class="source">void InitTriangulation();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_150

><td class="source">void InitEdges(std::vector&lt;Point*&gt; polyline);<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_151

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_152

><td class="source">};<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_153

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_154

><td class="source">inline AdvancingFront* SweepContext::front()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_155

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_156

><td class="source">  return front_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_157

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_158

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_159

><td class="source">inline int SweepContext::point_count()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_160

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_161

><td class="source">  return points_.size();<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_162

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_163

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_164

><td class="source">inline void SweepContext::set_head(Point* p1)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_165

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_166

><td class="source">  head_ = p1;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_167

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_168

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_169

><td class="source">inline Point* SweepContext::head()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_170

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_171

><td class="source">  return head_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_172

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_173

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_174

><td class="source">inline void SweepContext::set_tail(Point* p1)<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_175

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_176

><td class="source">  tail_ = p1;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_177

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_178

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_179

><td class="source">inline Point* SweepContext::tail()<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_180

><td class="source">{<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_181

><td class="source">  return tail_;<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_182

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_183

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_184

><td class="source">}<br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_185

><td class="source"><br></td></tr
><tr
id=sl_svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7_186

><td class="source">#endif<br></td></tr
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
 <a href="/p/poly2tri/source/detail?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&amp;r=5de9623d6a500d8b0ad3126a48957c5152c15ad2">5de9623d6a50</a>
 by Mason Green &lt;mason.green&gt;
 on Aug 8, 2011
 &nbsp; <a href="/p/poly2tri/source/diff?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=5de9623d6a500d8b0ad3126a48957c5152c15ad2&amp;format=side&amp;path=/poly2tri/sweep/sweep_context.h&amp;old_path=/poly2tri/sweep/sweep_context.h&amp;old=e501f94b9adc60ff188f0a446436f6e19bfc0eb4">Diff</a>
 </div>
 <pre>fixed NULL</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/poly2tri/source/detail?r=5de9623d6a500d8b0ad3126a48957c5152c15ad2&spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7';
 var publish_url = '/p/poly2tri/source/detail?r=5de9623d6a500d8b0ad3126a48957c5152c15ad2&spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/poly2tri/sweep/sweep_context.h');
 changed_urls.push('/p/poly2tri/source/browse/poly2tri/sweep/sweep_context.h?r\x3d5de9623d6a500d8b0ad3126a48957c5152c15ad2\x26spec\x3dsvnacf81f1f17647fe9574e3ae8f7a1731ee11085c7');
 
 var selected_path = '/poly2tri/sweep/sweep_context.h';
 
 
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
 
 <option value="/p/poly2tri/source/browse/poly2tri/sweep/sweep_context.h?r=5de9623d6a500d8b0ad3126a48957c5152c15ad2&amp;spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7"
 selected="selected"
 >/poly2tri/sweep/sweep_context.h</option>
 
 </select>
 </td></tr></table>
 
 
 



 <div style="white-space:nowrap">
 Project members,
 <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=http%3A%2F%2Fcode.google.com%2Fp%2Fpoly2tri%2Fsource%2Fbrowse%2Fpoly2tri%2Fsweep%2Fsweep_context.h&amp;followup=http%3A%2F%2Fcode.google.com%2Fp%2Fpoly2tri%2Fsource%2Fbrowse%2Fpoly2tri%2Fsweep%2Fsweep_context.h"
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
 <a href="/p/poly2tri/source/detail?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=e501f94b9adc60ff188f0a446436f6e19bfc0eb4">e501f94b9adc</a>
 by zzzz...@zzzzrrr-laptop
 on Apr 25, 2010
 &nbsp; <a href="/p/poly2tri/source/diff?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=e501f94b9adc60ff188f0a446436f6e19bfc0eb4&amp;format=side&amp;path=/poly2tri/sweep/sweep_context.h&amp;old_path=/poly2tri/sweep/sweep_context.h&amp;old=171bbe7f83908ca8a6c0790158b5f673c7cf1720">Diff</a>
 <br>
 <pre class="ifOpened">memory cleanup</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/poly2tri/source/detail?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=171bbe7f83908ca8a6c0790158b5f673c7cf1720">171bbe7f8390</a>
 by zzzzrrr &lt;mason.green&gt;
 on Apr 23, 2010
 &nbsp; <a href="/p/poly2tri/source/diff?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=171bbe7f83908ca8a6c0790158b5f673c7cf1720&amp;format=side&amp;path=/poly2tri/sweep/sweep_context.h&amp;old_path=/poly2tri/sweep/sweep_context.h&amp;old=cc86a7f3e81cf6aa703ee3199c4a7ee052c9992c">Diff</a>
 <br>
 <pre class="ifOpened">general cleanup</pre>
 </div>
 
 <div class="closed" style="margin-bottom:3px;" >
 <img class="ifClosed" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/plus.gif" >
 <img class="ifOpened" onclick="_toggleHidden(this)" src="http://www.gstatic.com/codesite/ph/images/minus.gif" >
 <a href="/p/poly2tri/source/detail?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=cc86a7f3e81cf6aa703ee3199c4a7ee052c9992c">cc86a7f3e81c</a>
 by zzzzrrr &lt;mason.green&gt;
 on Feb 7, 2010
 &nbsp; <a href="/p/poly2tri/source/diff?spec=svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7&r=cc86a7f3e81cf6aa703ee3199c4a7ee052c9992c&amp;format=side&amp;path=/poly2tri/sweep/sweep_context.h&amp;old_path=/poly2tri/sweep/sweep_context.h&amp;old=9130cf422d85016277acc4d9836a0181d4b93a7c">Diff</a>
 <br>
 <pre class="ifOpened">added include guards</pre>
 </div>
 
 
 <a href="/p/poly2tri/source/list?path=/poly2tri/sweep/sweep_context.h&r=5de9623d6a500d8b0ad3126a48957c5152c15ad2">All revisions of this file</a>
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
 
 <div>Size: 4275 bytes,
 186 lines</div>
 
 <div><a href="//poly2tri.googlecode.com/hg/poly2tri/sweep/sweep_context.h">View raw file</a></div>
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
 var paths = {'svnacf81f1f17647fe9574e3ae8f7a1731ee11085c7': '/poly2tri/sweep/sweep_context.h'}
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

 
 


 
 </body>
</html>

