<?php

     $article_header = "
		 <div class='header_image_container'>
		     <img class='header_img' itemscope itemprop='image' itemtype='http://schema.org/ImageObject' itemprop='url contentUrl' src='".$background_image."' alt='".$alt."'>
		     <h1 itemprop='headline'>".$h1."</h1>
			 <meta itemprop='url' content='".$background_image."'>
			 <meta itemprop='width' content='".$meta_width."'>
			 <meta itemprop='height' content='".$meta_height."'>
		 </div>
		 <div class='border-bottom' style='background-image:".$border_bottom."'></div>
	 ";

    echo $article_header;
	
?>