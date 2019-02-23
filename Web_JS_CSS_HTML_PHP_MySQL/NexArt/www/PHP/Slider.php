<?php
  $li_s = "";

  for($i = 0; $i < count($mass_img); $i += 3){
	  $size = getimagesize($mass_img[$i]);
	  
	  $li_s .= "<li class='frame_block'><p class='hint'>".$mass_img[$i + 2]."</p><img data-img='"
	  .$mass_img[$i]."' alt='".$mass_img[$i + 1]."' data-width='".$size[0]."' data-height='".$size[1]."'></li>";
  }
  
  $slider = "<div class='".$width." slider' data-index='0'>
        <div class='greyScreen'></div>
		<div data-visible='0' class='prev'>
			<i class='fa fa-chevron-left' aria-hidden='true'></i>
		</div>
		<div class='frames'>
			<ul>".
	            $li_s.
	        "</ul>
		</div>
		<div data-visible='1' class='next'>
			<i class='fa fa-chevron-right' aria-hidden='true'></i>
		</div>
	</div>";

  echo $slider;
?>