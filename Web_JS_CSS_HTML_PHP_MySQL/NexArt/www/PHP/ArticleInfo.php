<?php
   $year = ""; $month = ""; $day = "";
   
   $months = array("Января", "Февраля", "Марта", "Апреля", "Мая", "Июня", "Июля", "Августа", "Сентября"
				  , "Октября", "Ноября", "Декабря");

   function GetNumberMonth($str){
	   if($str[0] == "0")
		   return $str[1] + 0;
	   
	   return $str + 0;
   }

   $cur_value = ""; $step = 0;
   
   for($i = 0; $i < strlen($datePublished); $i++){
	   if($datePublished[$i] != "-"){
		  $cur_value .= $datePublished[$i];
	   }
	   else{
		  switch ($step){
				  
			  case 0:
				  $year = $cur_value;
				  break;
				  
			  case 1:
				  $month = $months[GetNumberMonth($cur_value) - 1];
				  break;
				
			  default:
				break;
		  }
		  $step++;
		  $cur_value = "";
	   }
   }

   $day = $cur_value;
   echo "
       </br></br></br></br>
       <p class='article_text'>
		<span class='prop_name'>Дата публикации: </span><time  itemprop='datePublished' datetime='".$datePublished."T00:00:00+00:00'>".$day." ".$month." ".$year." г."."</time>
		</p>
		
		
		<p class='article_text'>
	        <span class='prop_name'>Автор: </span><span class='autor' itemprop='author' >Матясов Михаил</span>
			</br>
			<span class='href' data-href='https://vk.com/id170454338'><img class='avatar' src='/my_photo.jpg' alt='Аватар'></span>
		</p>
		
		
		
		<div itemprop='publisher' itemscope itemtype='https://schema.org/Organization'>
        <div itemprop='logo' itemscope itemtype='https://schema.org/ImageObject'>
            <img itemprop='url image' src='/BigLogo.jpg' style='display:none;' />
            <meta itemprop='width' content='64'>
            <meta itemprop='height' content='64'>
        </div>
        <meta itemprop='name' content='NexArt'>
        <meta itemprop='telephone' content='+7 987 540 68 37'>
        <meta itemprop='address' content='Нижний Новгород'>
    </div>
   "
?>