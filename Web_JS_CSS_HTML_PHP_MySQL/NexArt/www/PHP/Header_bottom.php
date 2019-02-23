<?php
 $fixed_header = "<header id='fixed_header'>".
	        "<div class='container_menu'>
			  <div class='portrait_menu'>
			    <i class='fa fa-times' aria-hidden='true'></i>".
				"<div id='portrait_sections'>".
					"<a href='/index.php'><img class='logo' alt='logo' src='/NexArt_Logo.svg'></a>".
					"<div data-section='portrait-section' class='section'>
					  <span  class='defaultRef' href='".$path_AllArticles."' ></span><span>Все статьи</span>
					</div>".
				    "</div>".
			   "</div>".
			  "</div>".
			"</div>".
	        "<div class='bar-container'><i class='fa fa-bars' aria-hidden='true'></i></div>".
			"<div itemscope itemtype='http://schema.org/SiteNavigationElement'  id='sections'>".
	            "<a href='/index.php'><img class='logo' alt='logo' src='/NexArt_Logo.svg'></a>".
				"<div data-section='section' data-select='".$main_select."'  class='section'><span  class='defaultRef' href='".$path_AllArticles."' ></span><span>Все статьи</span></div>".
				"</div>".
			"</div>".
		"</header>".
	 "<div class='load_bar'></div>";

 $header = "</head>".
	"<body>".
	"<!--LiveInternet counter--><script type='text/javascript'>
	new Image().src = '//counter.yadro.ru/hit?r'+
	escape(document.referrer)+((typeof(screen)=='undefined')?'':
	';s'+screen.width+'*'+screen.height+'*'+(screen.colorDepth?
	screen.colorDepth:screen.pixelDepth))+';u'+escape(document.URL)+
	';h'+escape(document.title.substring(0,150))+
	';'+Math.random();</script><!--/LiveInternet-->".
		"<header  itemscope itemtype='http://schema.org/WPHeader'  id='defaultHeader'>".
	    "<meta itemprop='headline' content='".$title."'>
        <meta itemprop='description' content='".$discription."'>
        <meta itemprop='keywords' content='".$keywords."'>".
	        "<div class='container_menu'>
			  <div itemscope itemtype='http://schema.org/SiteNavigationElement' class='portrait_menu'>
			    <i class='fa fa-times' aria-hidden='true'></i>".
				"<div id='portrait_sections'>".
					"<a href='/index.php'><img class='logo' alt='logo' src='/NexArt_Logo.svg'></a>".
					"<div data-section='portrait-section' class='section'>
					  <span itemprop='url' class='defaultRef' href='".$path_AllArticles."' ></span><span>Все статьи</span>
					</div>".
				    "</div>".
			   "</div>".
			  "</div>".
			"</div>".
	        "<div class='bar-container'><i class='fa fa-bars' aria-hidden='true'></i></div>".
			"<div id='sections'>".
	            "<a href='/index.php'><img class='logo' alt='logo' src='/NexArt_Logo.svg'></a>".
				"<div data-section='section' data-select='".$main_select."'  class='section'><span  class='defaultRef' href='".$path_AllArticles."' ></span><span>Все статьи</span></div>".
				"</div>".
			"</div>".
         $fixed_header.
		"</header>";

 echo $header;
?>