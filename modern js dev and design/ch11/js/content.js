window.onload = function()	{
	'use strict';
	
	var pages = ['model', 'view', 'controller'];
	var counter = 0;

	var ajax = getXMLHttpRequestObject();
	ajax.open('GET', 'resources/content.php?id=' + pages[counter], false);
	ajax.send(null);

	var title = ajax.responseXML.getElementsByTagName('title')[0].firstChild.nodeValue;
	var content = ajax.responseXML.getElementsByTagName('content')[0].firstChild.nodeValue;

	var nextLink = document.getElementById('nextLink');

	nextLink.onclick = function()	{
		document.getElementById('title').innerHTML = title;
		document.getElementById('content').innerHTML = content;
		counter++;
		if (counter == 3) {
			nextLink.parentNode.removeChild(nextLink);
			ajax = null;
		} else {
			ajax.open('GET', 'resources/content.php?id=' + pages[counter], false);
			ajax.send(null);
			title = ajax.responseXML.getElementsByTagName('title')[0].firstChild.nodeValue;
			content = ajax.responseXML.getElementsByTagName('content')[0].firstChild.nodeValue;
		}
		return false;
	}
}
