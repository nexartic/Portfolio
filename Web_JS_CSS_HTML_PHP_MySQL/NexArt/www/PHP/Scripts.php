<?php
$version = "96";

$raiting = "
<script type='text/javascript'>
wpac_init = window.wpac_init || [];
wpac_init.push({widget: 'Rating', id: 15765});
(function() {
    if ('WIDGETPACK_LOADED' in window) return;
    WIDGETPACK_LOADED = true;
    var mc = document.createElement('script');
    mc.type = 'text/javascript';
    mc.async = true;
    mc.src = 'https://embed.widgetpack.com/widget.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(mc, s.nextSibling);
})();
</script>";

$review = "
<script type='text/javascript'>
wpac_init = window.wpac_init || [];
wpac_init.push({widget: 'Review', id: 15765});
(function() {
    if ('WIDGETPACK_LOADED' in window) return;
    WIDGETPACK_LOADED = true;
    var mc = document.createElement('script');
    mc.type = 'text/javascript';
    mc.async = true;
    mc.src = 'https://embed.widgetpack.com/widget.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(mc, s.nextSibling);
})();
</script>";
 
 $raiting_widget = $raiting.$review;
 if(isset($display))
	 $raiting_widget = "";

 $scripts =
	  "<script type='text/javascript' src='//ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js'></script>".
      "<script type='text/javascript' src='/JS/inview.js'></script>".
	  "<script type='text/javascript' src='/JS/jquery.lazyload.min.js?v=1.2.".$version."'></script>".
      "<script type='text/javascript' src='/JS/Script.min.js?v=1.2.".$version."'></script>".
	  $raiting_widget;

echo $scripts;
?>