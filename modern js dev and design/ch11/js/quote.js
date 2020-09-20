window.onload = function()	{
	'use strict';
	var ajax = getXMLHttpRequestObject();
	ajax.onreadystate = function()	{
		if (ajax.readyState == 4)	{
			var data = JSON.parse(ajax.responseText);
			var output = document.getElementById('quote');
			if (output.textContent !== undefined){
				output.textContent = data[0].l;
			} else {
				output.innerText = data[0].l;
			}
		}
	}

	ajax.open('GET', 'resources/quote.php', true);
	ajax.send(null);

	var stockTimer = setInterval(function()	{
		ajax.open('GET', 'resources/quote.php', true);
		ajax.send(null);
	}, 15000);
}
