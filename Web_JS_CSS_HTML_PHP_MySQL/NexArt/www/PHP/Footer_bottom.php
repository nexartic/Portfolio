<?php
$info = "
	<div id='info_panel'>
	  <div id='liveInternet'>
	    <!--LiveInternet logo--><a href='//www.liveinternet.ru/click'
        target='_blank'><img class='list_point' src='//counter.yadro.ru/logo?26.5'
        title='LiveInternet: показано число посетителей за сегодня'
        alt=' border='0' width='88' height='15'/></a><!--/LiveInternet-->
      </div>
	</div>
";

 $footer_bottom =
	 "<div ".$display." class='vk_container'><div id='wpac-review'></div></div>".
	 $info.
	"</footer>";
 echo $footer_bottom;
?>
