var TBLOCK = "<div class='block' data-index=''>"+
				"<div class='top'>"+
	                "<i class='fa fa-eraser' aria-hidden='true'></i>" +
					"<i class='fa fa-arrows-alt' aria-hidden='true'></i>"+
				"</div>"+
				"<div class='bottom'>"+
					"<div class='edit'>"+
						"<i class='fa fa-pencil' aria-hidden='true' role='listbox'></i>"+
					"</div>"+
					
					"<div class='share' >"+
						"<ul>"+
							"<div id='listFolders'>"+
								"<div class='container'>"+
									"<div class='page'>"+
									"</div>"+
								"</div>"+
							"</div>"+
							"<i class='fa fa-share-square-o' aria-hidden='true' role='listbox'></i>"+
					    "</ul>"+
					"</div>"+
					
					"<div class='create'>"+	
						"<ul>"+
							"<div class='text' role='list'>"+
						        "<i class='fa fa-file-text' aria-hidden='true' role='list'></i>"+
							"</div>"+
							
							"<div class='image' role='list'>"+
							    "<i class='fa fa-picture-o' aria-hidden='true' role='list'></i>"+
								"<i class='fa fa-internet-explorer' aria-hidden='true' data-s='extra'></i>"+
                                "<i class='fa fa-folder-open-o' aria-hidden='true' data-s='extra'></i>"+
							"</div>"+
							
							"<div class='video' role='list'>"+
								"<i class='fa fa-video-camera' aria-hidden='true' role='list'></i>"+
							"</div>"+
							
							"<div class='music' role='list'>"+
								"<i class='fa fa-music' aria-hidden='true' role='list'></i>"+
							"</div>"+
						"</ul>"+	
						"<i class='fa fa-plus' aria-hidden='true' role='listbox'></i>"+		
				    "</div>"+
					
					"<div class='cross'>"+
						"<i class='fa fa-times' aria-hidden='true' role='listbox'></i>"+
					"</div>"+
				"</div>"+
			"</div>";

var INTERNET_IMAGE = "<div class='newImage'>"+
						"<div class='windowImage'>"+
							"<img src=''/>"+
						"</div>"+
						"<div class='reference'>"+
							"<div><i class='fa fa-times' aria-hidden='true'></i></div>"+
							"<input type='text' style='position:relative; z-index: 1;" +"placeholder='http://'>"+
							"<div><i class='fa fa-check' aria-hidden='true'></i></div>"+
							"<div><i class='fa fa-clone' aria-hidden='true'></i></div>"+
						"</div>"+
					"</div>";

var FILE_IMAGE = "<div class='newImage'>"+
						"<div class='windowImage'>"+
							"<img src=' alt='>"+
						"</div>"+
						"<div class='reference'>"+
							"<input class='imgFromFile' type='text'>"+
							"<div class='img-upload'>"+
								"<label>"+
									"<input type='file'>"+
									"<span>Выбрать</span>"+
								"</label>"+
							"</div>"+
						"</div>"+
					"</div>";

$(document).ready(function(){
	"use strict";
//---------------------------------
	function GetOuterHtml($block)
	{
	    $block.wrap("<div>");
		var $parent = $block.parent();
		var outerHtml = $parent.html();
		
		$(outerHtml).insertAfter($parent);
		$parent.remove();
		
		return outerHtml;
	}
//---------------------------------
	function GetParent(child)
	{
		return $(child).parent().parent().parent().parent().parent().children(".top");
	}
//---------------------------------
	function IsExist(tag,parent)
	{
		return $(parent).children(tag).length;
	}
//---------------------------------
	function CloseListBox(block,listBox)
	{
		HideListItems(listBox,block);
		$("i[role='listbox']",listBox).css({
			"color":"white"
		});
	}
//---------------------------------
	function AddEraser(block)
	{
		
		var eraser = $(block).children(".top").children(".fa-eraser");
		var alt_arrow = $(block).children(".top").children(".fa-arrows-alt");
		
		eraser.css({
			display:"block",
		});
		
		alt_arrow.css({
			"margin-left": "63%"
		});
	}
//---------------------------------
	function ChangeOpacityTopArea(op,mainBlock){
		$(".top",mainBlock).children().each(function(index,data){
			if(data.tagName !== "I"){
				$(data).css({
					opacity : op
				});
			}
		});
	}
	
	function HideListItems(create,mainBlock)
	{	
		ChangeOpacityTopArea("1",mainBlock);
		
		$(".newTextarea",mainBlock).focus();
		
		$("ul",create).animate({
			opacity:"0"
		},{
			duration: 100
		});
		
		$("ul div",create).animate({
			height:"0"
		},{
			duration: 100
		});
	    Down(create);
	}
//---------------------------------
	function ShowListItems(create,mainBlock)
	{
        ChangeOpacityTopArea("0.2",mainBlock);
		$(".newTextarea",mainBlock).blur();
		$(create).css({
			height: "420%"
		});
		
		$("ul",create).animate({
			opacity:"1",
		},{
			duration: 100
		});
		$("ul div",create).animate({
			height:"25%"
		},{
			duration: 100
		});
		
		Up(create);
//		
	}
	
	function Up($block){
		$block.css({
			"position":"relative",
			"z-index":"1"
		});
	}
	function Down($block){
		$block.css({
			"position":"relative",
			"z-index":"0"
		});
	}
//--------------------------------------------------------------------------------------------------------
	var colorI = "#FF891B";
	function AddEventHandler(block){
		
		
		$(".create ul",block).css({
            "opacity":"0",
		});

		//---------------------------------
		$(".create ul div",block).css({
			height:"0",
		});
		//---------------------------------
		$(".create i[role='listbox']",block).mouseenter(function(){	
			ShowListItems($(this).parent(),block);
		});//При наведении на +
		//---------------------------------
		$(".create",block).mouseleave(function(){	
			HideListItems($(this),block);
		});// Если курсор покинул весь блок, а не только значок +
		//---------------------------------
		$(".bottom div i",block).mouseenter(function(){
			$(this).css({"color":"#FF4700"});
			$(this).css({
				"cursor":"pointer"//Реализация hover
			});
		});
		$(".bottom div ul i",block).mouseenter(function(){
			$(this).css({"color":colorI});
			$(this).css({
				"cursor":"pointer"//Реализация hover
			});
		});
		$(".bottom .share ul i",block).mouseenter(function(){
			$(this).css({"color":"#FF4700"});
		});
		//---------------------------------
		$(".create",block).mouseleave(function(){
			$(".create i[role='listbox']",block).css({"color":"white"});
			$(this).css({
				"cursor":"default"// Отмена hover для +
			});
		});
		//---------------------------------
		// Отмена hover для остальных кнопок при уходе курсора с самой кнопки а не с блока
		$(".edit i",block).mouseleave(function(){
			$(this).css({
				"color":"white"
			});
			$(this).css({
				"cursor":"default"
			});
		});
		//---------------------------------
		$(".share i",block).mouseleave(function(){
			$(this).css({
				"color":"white"
			});
			$(this).css({
				"cursor":"default"
			});
		});
		//---------------------------------
		$(".cross i",block).mouseleave(function(){
			$(this).css({
				"color":"white"
			});
			$(this).css({
				"cursor":"default"
			});
		});
		//---------------------------------
		$(".bottom i[role='list'], .block .top i,i[data-s='extra']",block).css({
		"-webkit-transition": "font-size 0.1s ease",
		"-moz-transition": "afont-size0.1s ease",
		"-o-transition": "font-size 0.1s ease",
		"-ms-transition": "font-size 0.1s ease",
		"transition": "font-size 0.1s ease"
		});
		//---------------------------------
		$(".bottom i[role='list']",block).mouseenter(function(){
			$(this).css({
				"font-size": "1.1em",
				"color":"#FF4700"
			});
		});
		//---------------------------------
		$(".bottom i[role='list']",block).mouseleave(function(){
			$(this).css({
				"font-size": "0.9em",
				"color":colorI
			});
		});
		//---------------------------------
		$(".fa-file-text",block).click(function(){
			var top = GetParent(this);
		
			if(!IsExist("textarea",top))
			{
				top.children().each(function(index,data){
					if(data.tagName !== "I"){
						$(data).remove();
					}
				});
				var txtField = "<textarea class='newTextarea' placeholder='Печатать здесь'></textarea>";
				$(txtField).appendTo(top);
				var textarea = $(top).children("textarea");
				$(textarea).focus();
				CloseListBox(block,$(".create"));
				AddEraser(block);
			}
	    });
		//---------------------------------
		$(".cross i[role='listbox']",block).click(function(){
			var block = $(this).parent(".cross").parent(".bottom").parent(".block");
			block.animate({
				width: "0",
				opacity: "0",
				height: "-=10em"
			},{
				duration: 150,
				complete: function(){
					block.remove();
				}
			});
		});
		//---------------------------------
		$(".top .fa-arrows-alt",block).click(function(){
			var data = $(this).siblings(":last-of-type");
			if(data.length)
			{
				$("#largeWindow").show(150);
				$("body #blackScreen").css({display:"block"});
				$("body #blackScreen").animate({
					opacity:"0.7"
				},{
					duration: "50"
				});

				if(data.attr("class") === "newTextarea")
				{
					data.attr("class","largeTextarea");
					var eraser = $("#toolsLargeWindow .fa-eraser");
					eraser.css({
						display:"block"
					});
				}
				$(data).appendTo($("#largeWindow #fieldLargeWindow"));
				data.focus();
				$(block).attr("class","openedBlock");
			}
			else{alert("Блок пуст");}
		});
		//---------------------------------
		$(".top .fa-eraser",block).click(function(){
		    var data = $(this).siblings(":last-of-type");
			data.val("");
			data.focus();
		});
		//---------------------------------
		

		
		//+++++++++++++++++++++++++++++share
		function AddListFolder(page,bl){
			var $folder = $("#top .folder");
			if($folder.length > 1){
				$("<span class='hint' style='font-size:14px; letter-spacing: 0px; color: #555555; font-weight: bold;'>Переместить в :<br/></span>").appendTo(page);
				$folder.each(function(index,data){
					var $clone = $("<span>");
					var folderIndex = $(data).attr("data-index");
					var folderName = $(data).find("input").val();
					
					if($(bl).attr("data-index") !== folderIndex){
						$clone.appendTo(page);
						$clone.attr("data-index",folderIndex);
						$clone.html(folderName);
						
						$clone.click(function(){
							
							var index = $clone.attr("data-index");
							
							$(bl).attr("data-index",index);
							$(bl).css({
								display: "none"
							});
							
					    });
					}
				});
			}
			else{
				$("<span class='hint'>Других папок нет</span>").appendTo(page);
			}
		//--------------------------------------------------------------------	
			
		}
		function RemoveListFolder($page){
			$page.find("span").remove();
		}
		//-----------------------------------
		$(".share #listFolders .container",block).css({
			display:"none",
			opacity:"0"
		});
		//-----------------------------------
		var retCode = 0;
		var speed = 50;
		var isOpenShare = 0;
		$(".share ul i",block).mouseenter(function(){
			Up($(".share ul",block));
			retCode = 1;
			$(".folder input").blur();
			$(".newTextarea",block).css({
				opacity:"0.2"
			});
			var list = $(this).siblings("#listFolders").children();
			
			if(isOpenShare === 0){
				RemoveListFolder(list.children(".page"));
				AddListFolder(list.children(".page"),block);
			}
			isOpenShare = 1;
			
			list.css({
				display:"block",
			    opacity:"1"
			});
		});
		//----------------------------------------------
		$(".share ul i",block).mouseleave(function(){
			retCode = 0;
			setTimeout(function(){
				if(retCode === 0){
					Down($(".share ul",block));
					isOpenShare = 0;
					var list = $(".share ul i",block).siblings("#listFolders").children();
					list.css({
						opacity:"0"
					});
					
					setTimeout(function(){
						list.css({
						  display:"none"
						});
					
				},speed);
	               $(".newTextarea",block).css({
				      opacity:"1"
			       });
				}
				
			},1);
			
		});
		//----------------------------------------------
		$(".share .container",block).mouseenter(function(){
			retCode = 1;
			$(".share ul i[role='listbox']",block).css({
				"color":"#FF4700"
			});
		});
		//----------------------------------------------
		$(".share .container",block).mouseleave(function(){
			retCode = 0;
			var $container = $(".share .container",block);
			setTimeout(function(){
			if(retCode === 0){
				Down($(".share ul",block));
				isOpenShare = 0;
				$container.fadeOut(speed);
				$(".share ul i[role='listbox']",block).css({
					"color":"white"
				});
				
				setTimeout(function(){
					$container.css({
					  display:"none"
			        });
				},speed);
				
				$(".newTextarea",block).css({
				opacity:"1"
			    });
			}
			},1);
			
		});
		//----------------------------------------------
		//+++++++++++++++++++++++++++++++++++++++++++
		
		//++++++++++++++++++++++++++++++++++++++++++plus->image
		var speedImage = 70;
		var imageIsOpen = 0;
		function HideImage($extra){
			$($extra[1]).animate({
				opacity: "0",
				"font-size":"0em"
			},{
				duration: speedImage
			});
			setTimeout(function(){
				$($extra[0]).animate({
				opacity: "0",
				"font-size":"0em"
				},{
					duration: speedImage
				});
			},speedImage);
			
			setTimeout(function(){
				$extra.css({
				   display: "none"
			    });
			},speedImage*2);
			imageIsOpen = 0;
		}
		function ShowImage($extra){
			if(imageIsOpen === 0){
			$extra.css({
				   display: "block"
			    });
			
			$($extra[0]).animate({
				opacity: "1",
				"font-size":"0.9em"
			},{
				duration: speedImage
			});
			setTimeout(function(){
				$($extra[1]).animate({
				opacity: "1",
				"font-size":"0.9em"
				},{
					duration: speedImage
				});
			},speedImage);
			imageIsOpen = 1;
			}
		}
		$(".create .image i[role='list']",block).mouseenter(function(){
			var $extra = $(this).siblings("i[data-s='extra']");
			ShowImage($extra);
		});
		//-----------------------------------------------
		$(".create .image",block).mouseleave(function(){
			var $extra = $(this).children("i[data-s='extra']");		
			HideImage($extra);
		});
		//-----------------------------------------------
		$(".create .image i[data-s='extra']",block).mouseenter(function(){
			$(this).css({
				"font-size":"1.1em",
				"color":"#FF4700"
			});
		});
		//-----------------------------------------------
		$(".create .image i[data-s='extra']",block).mouseleave(function(){
			$(this).css({
				"font-size":"0.9em",
				"color":colorI
			});
		});
		//-----------------------------------------------
		$(".create .image i[data-s='extra']",block).click(function(){
			HideListItems($(".create",block),block);
			
			var $top = $(".top");
			$top.find(".fa-eraser").css({
				display: "none"
			});
			
			
			$top.find(".fa-arrows-alt").css({
				"margin": "0 0 0 80%"
			});
		});
		//-----------------------------------------------
		$(".create .image .fa-internet-explorer",block).click(function(){
			var $top = $(block).children(".top");
			var $input = $(".newImage .reference input");
			Up($input);
			
			$top.children().each(function(index,data){
				if(data.tagName !== "I"){
					$(data).remove();
				}
			});
			
			$(INTERNET_IMAGE).appendTo($top);
			AddEventInternetImage(block);
		});
		//-----------------------------------------------
		$(".create .image .fa-folder-open-o",block).click(function(){
			var $top = $(block).children(".top");
			var $input = $(".imgFromFile");
			Up($input);
			
			$top.children().each(function(index,data){
				if(data.tagName !== "I"){
					$(data).remove();
				}
			});
			
			$(FILE_IMAGE).appendTo($top);
			AddEventFileImage(block);
		});
		
		
	}
	AddEventHandler($("#bottom .block")[0]);
	
	//-----------------------------------------------------------------------------------------------------
	
	function PutImageToWindow($img,block){
		var $window = $(".newImage .windowImage",block);
		var mrgn;
			$img[0].onerror = function(){
				alert("Не удалось загрузить изображение");
			};
		    
			$img[0].onload = function(){
				var coeff = $img.height() / $img.width();
		        var futureHeight = $window.width() * coeff;
				if($img.width() > $img.height() && futureHeight < $window.height()){
					
					$img.css({
						width: "100%",
						height: "auto"
					});
					
					setTimeout(function(){
						mrgn = String(($window.height() - $img.height()) / 2);
						$img.css({
							margin: mrgn +"px "+ "0 "+ mrgn+"px " + "0",
							opacity: "1"
					    });
					},10);
					
				}
				else{
					$img.css({
						width: "auto",
						height: "calc(100% - 0.03em)"
					});
					
					setTimeout(function(){
					mrgn = String(($window.width() - $img.width()) / 2);
						$img.css({
							margin: "0.02em "+ mrgn +"px "+ "0.01em "+ mrgn+"px",
							opacity: "1"
					    });
				    },10);
				}
			};
	}
	function AddEventFileImage(block){
		$(".newImage .reference input[type='file']",block).change(function(){
			var file = $(this)[0].files[0];
			var pattern = new RegExp("image/+");
			var $obj = $(this);
			
			if(pattern.test(file.type)){
				var $img = $(this).parent().parent().parent().siblings(".windowImage").children("img");
				var reader = new FileReader();
				reader.onload = function(e){
					$img.attr("src",e.target.result);
					$img.css({
						opacity: 1
					});
					var $input = $obj.parent().parent().siblings("input");
					$input.val(file.name + ", " + (file.size / 1024).toFixed(0)+ "KB");
					$input.focus();
				};

				reader.readAsDataURL(file);
				PutImageToWindow($img,block);
			}
			else{
				alert("Загружаемый файл не является изображением");
			}
		});
	}
	function AddEventInternetImage(block){
		$(".newImage .reference .fa-check",block).click(function(){
			var $input = $(this).parent().siblings("input");
			var src = $input.val();
			$input.focus();
			var $img = $(this).parent().parent().siblings(".windowImage").children("img");
			$img.attr("src",src);
			PutImageToWindow($img,block);	
		});
		
		$(".newImage .reference .fa-times",block).click(function(){
			$(this).parent().siblings("input").val("").focus();
		});
		$(".newImage .reference .fa-clone",block).click(function(){
			$(this).parent().siblings("input").select();
		});
	}
	
	$("#toolsLargeWindow .fa-eraser").click(function(){
		
		var textarea = $(this).parent().siblings().children();
		var clone = textarea.clone();
		clone.val("");
		textarea.remove();
		$(clone).appendTo("#fieldLargeWindow");
		clone.focus();
	});
	//---------------------------------
	// События bottomPlus
	
	$("#fixedInterface i").mouseenter(function(){

		$(this).css({
			color:"#FF4700",
			cursor:"pointer"
		});
    });
	//---------------------------------
	$("#fixedInterface i").mouseleave(function(){
		$(this).css({
			color:"#FF891b",
			cursor:"default"
		});
	});
	//---------------------------------
	$("#bottomPlus").click(function(){
		
		var clone = $(TBLOCK);
		var massFolder = $(".frame ul li");
		var folderName = "";
		massFolder.each(function(index,data){
			if($(data).attr("class") === "folder active"){
				folderName = $(data).attr("data-index");
			}
		});
		clone.attr("data-index",folderName);
		clone.insertBefore($("#fixedInterface"));
		AddEventHandler(clone);
        var page = document.getElementById("bottom");
		page.scrollTop = page.scrollHeight;
		
		clone.css({
			opacity:"0",
			width: "0",
			height: "25%"
		});
		clone.animate({
			opacity:"1",
			height: "40%",
	        width: "20%",
	        margin: "10% 0% 10% 10%"
		},{
			duration: 150
		});
	});
	//---------------------------------
	$("#deleteAll").click(function(){
		var massFolder = $(".frame ul li");
		var activeFolder = "";
		massFolder.each(function(index,data){
			if($(data).attr("class") === "folder active"){
				activeFolder = $(data).attr("data-index");
			}
		});
		$(".block").each(function(index,data){
			if($(data).attr("data-index") === activeFolder){
				$(data).remove();
			}
		});
	});
	//---------------------------------
	// события LargeWindow
	$("#largeWindow").hide();
	$("#blackScreen").css({
			opacity:"0",
			display:"none"
	});
	//---------------------------------
	$("#largeWindow #toolsLargeWindow i").mouseenter(function(){
			$(this).css({
				color:"#FF4700",
				cursor:"pointer"
			});
	});
	//---------------------------------
	$("#largeWindow #toolsLargeWindow i").mouseleave(function(){
			$(this).css({
				color:"white",
				cursor:"default"
			});
	});
	//---------------------------------
	$("#largeWindow #toolsLargeWindow #crossLW").click(function(){
			$("#largeWindow").hide(100);
			$("#blackScreen").css({display:"none"});
			$("#blackScreen").animate({
				opacity:"0"
			},{
				duration: "100"
			});
		    
		    var top = $(".openedBlock").children(".top");
		    var data = $("#largeWindow #fieldLargeWindow").children();
		    $(data).appendTo(top);
		    data.focus();
		    
		    $(".openedBlock").attr("class","block");
		    if($(data).attr("class") === "largeTextarea"){
				top.children("textarea").attr("class","newTextarea");
			}
		    
	});
	//---------------------------------
});