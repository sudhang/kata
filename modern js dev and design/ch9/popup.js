function createPopup(e){
	'use strict';

	if (typeof e == 'undefined'){ var e = window.event; }
	var target = e.target || e.srcElement;

	var popup = window.open(target.href, 'PopUp', 
					'height=100, width=100, top=100, left=100, location=no, resizable=yes, scrollbars=yes');	
	if ( (popup !== null) && !popup.closed ){
		popup.focus();
		return false;
	}
}

window.onload = function (){
	'use strict';
	var popUpLinks = document.getElementsByClassName('popup');
	for (var i = 0, count = popUpLinks.length; i < count; i++){
		documents.links[i].onclick = createPopup;
	};
}
