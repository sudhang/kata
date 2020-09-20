function toggleCheckboxes(){
	'use strict';

	var	status = document.getElementById('toggle').checked;
	var boxes = document.querySelectorAll('input[class="pizzaTopping"]');

	for (var i = 0; i < boxes.length; i++){	
		boxes[i].checked = status;
	}

}

window.onload = function()	{
	'use strict';

	document.getElementById('toggle').onchange = toggleCheckboxes;
}
