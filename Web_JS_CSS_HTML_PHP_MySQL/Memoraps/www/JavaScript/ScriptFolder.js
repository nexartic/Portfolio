
jQuery(function($){
	'use strict';
	
	$("#top button i").mouseenter(function(){
		$(this).css({
			cursor:"pointer",
			color:"#FF4700"
		});
	});
	//-----------------------------------------
	$("#top button i").mouseleave(function(){
		$(this).css({
			cursor:"default",
			color:"#FFA24C"
		});
	});
	//-----------------------------------------
	
	 document.getElementsByTagName('html')[0].className += ' ' +
		(~window.navigator.userAgent.indexOf('MSIE') ? 'ie' : 'no-ie');
	
	var $top = $('#top');
	var $frame = $top.find('.frame');
	window.frr = $frame;
	var sly = new Sly($frame, {
		horizontal: 1, //ризонтальная прокрутка в значении true
		itemNav: 'basic',// при каждом нажатии кнопки  frame будет сентрироваться , указать 'basic' для отмены
		smart: 1,// будет ли прокручиваться бар при достижении границы выделенным объектом
		activateOn: 'click',// при каком событии активируется элемент
		releaseSwing: 1,// время анимации прокрутки[0,1]
		startAt: 0,// стартовая позиция
		scrollBy: 1,// будут ли скролится объекты при вращение колесиком мыши
		speed: 200,// скорость промотки колесиком
		moveBy: 2500,// скорость используемая forward bacward
		elasticBounds: 1,
		touchDragging: 1,

		// Buttons
		forward: $top.find('.forward'),// постоянная прокрутка вперед, самая правая кнопка
		backward: $top.find('.backward'),//постоянная прокрутка назад, самая левая кнопка

	}).init();
	
	
function AddEventHandler(folder){
    
    $("i",folder).mouseenter(function(){
		$(this).css({
			cursor:"pointer",
			color:"#FF4700"
		});
	});
	//---------------------------------
	$("i",folder).mouseleave(function(){
		$(this).css({
			cursor:"default",
			color:"white"
        });
	});
	//---------------------------------
	
	function RemoveBlocksFromFolders($blocks,$folder){
		var folderIndex = $folder.attr("data-index");
		$blocks.each(function(index,data){
			if($(data).attr("data-index") === folderIndex){
				$(data).remove();
			}
		});
	}
	function TransformToOtherFolder($blocks,folderName){
		$blocks.each(function(index,data){
				if($(data).attr("data-index") === folderName){
					$(data).css({
						display: "block"
					});
				}
				else{
					$(data).css({
						display: "none"
					});
				}
			});
	}
	$(".remove",folder).click(function(){
		var $blocks = $(".block");

		if(sly.items.length > 1){
			var $parent = $(this).parent();
			var folderName = $parent.attr("data-index");
			
			var $folders = $(".folder");
			$folders.each(function(index,data){// индекс, сам объект(outer html)
				if($(data).attr("data-index") === folderName){
					if($(data).attr("class") === "folder active"){
						sly.activate(index - 1);
					}
					sly.remove(index);
					RemoveBlocksFromFolders($blocks,$(data));
					var data_index = $($folders[index-1]).attr("data-index");
					TransformToOtherFolder($blocks,data_index);
				}	
			});
		}
		else{
			$blocks.remove();
		}

	});
	
	//---------------------------------
	$("input",folder).focusout(function(){
		
		var $obj = $(this);
		var folderName = $obj.val();
			if(folderName === ""){
		       $obj.val("Папка");
		    }
		
		$obj.attr("disabled","disabled");
		$obj.css({
			cursor: "pointer"
		});
	});
	//---------------------------------
	$(".fa-pencil",folder).click(function(){
		
		var obj = $(this).siblings("input");
		obj.removeAttr("disabled");
		var value = obj.val();
		obj.val("");
		obj.focus();
		obj.val(value);

		obj.css({
			cursor: "text"
		});
	});
	//----------------------------------------
	$(folder).click(function(e){
		if(e.target.tagName !== "I"){
		    var $blocks = $(".block");
			var currentFolderName = $(this).attr("data-index");
			
			TransformToOtherFolder($blocks,currentFolderName);
		}
	});
}
AddEventHandler($(".folder"));
	
//---------------------------------	
$("#centerPanel #top .add").click(function(){
	var data = new Date();
	var folder = "<li class='folder'  data-index='"+Date.parse(data) + data.getMilliseconds()+"'>"+
		            "<i class='fa fa-pencil' aria-hidden='true'></i>"+
					"<input type='text' maxlength='14'>"+
					"<button class='remove'><i class='fa fa-times' aria-hidden='true'></i></button>"+
				"</li>";
	var $clone = $(folder);

	sly.add($clone);
	AddEventHandler($clone);
	$clone.find("input").focus();
	sly.toEnd();
});
//---------------------------------
});
