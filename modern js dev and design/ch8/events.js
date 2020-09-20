function reportEvent(e){
	'use strict';
	//if (typeof e == 'undefined'){ e = window.event; }
	e = e || window.event;
	var target = e.target || e.srcElement;
	var msg = target.nodeName + ': ' + e.type + '\n';
	U.$('output').value += msg;
}

function setHandlers(e){
	'use strict';
	var events = ['mouseover', 'mouseout', 'click', 'keypress', 'blur'];
	for (var i = 0, count = events.length; i < count; i++){
		var checkbox = U.$(events[i]);
		if (checkbox.checked){
			U.addEvent(document, events[i], reportEvent);
		} else {
			U.removeEvent(document, events[i], reportEvent);
		}
	}
	U.$('output').value = '';
	return false;
}

window.onload = function()	{
	'use strict';
	U.$('theForm').onsubmit = setHandlers;
}
