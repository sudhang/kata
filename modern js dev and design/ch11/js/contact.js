function handleAjaxResponse(e){
	'use strict';

	if (typeof e == 'undefined'){ e = window.event; }

	var ajax = e.target || e.srcElement;

	if (ajax.readyState == 4){
			/*
		if ( (ajax.status >= 200 && ajax.status < 300) || (ajax.status == 304) )	{
			document.getElementById('contactForm').innerHTML = ajax.responseText;
		} else {
			document.getElementById('theForm').submit();
		}
		*/
		document.getElementById('contactForm').innerHTML = ajax.responseText;
		ajax = null;
	}
}

window.onload = function()	{
	'use strict';
	var ajax = getXMLHttpRequestObject();
	ajax.onreadystatechange = handleAjaxResponse;

		document.getElementById('theForm').onsubmit = function()	{
			var fields = ['name', 'email', 'comments'];
			var data = [];
			for (var i = 0; i < fields.length; i++){
				data.push(encodeURIComponent(fields[i]) + '=' + encodeURIComponent(document.getElementById(fields[i]).value));
			};
			ajax.open('POST', 'resources/contact.php', true);
			ajax.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
			ajax.send(data.join('&'));
			return false;
		}
}
