function updateMenu()	{
	'use strict';
	var os = document.getElementById('os');
	var os2 = document.getElementById('os2');

	var options = null;

	while (os2.firstChild)	{
		os2.removeChild(os2.firstChild);
	}
	
	if (os.value == 'Windows'){
		options = ['7 Home Basic', '7 Home Premium', '7 Professional', '7 Ultimate', 'Vista', 'XP'];
	}
	else if(os.value == 'Mac OS X'){
		options = ['10.7 Lion', '10.6 Snow Leopard', '10.5 Leopard', '10.4 Tiger'];
	}

	if (options){
		os2.disabled = false;
		for (var i = 0; i < options.length; i++){
			var opt = document.createElement('option');
			opt.text = opt.value = options[i];
			os2.appendChild(opt);
		}
	} else {
		os2.disabled = true;
	}
}

window.onload = function()	{
	'use strict';
	var os = document.getElementById('os');
	while (os.firstChild)	{
		os.removeChild(os.firstChild);
	}

	var options = ['Choose', 'Windows', 'Mac OS X'];
	for (var i = 0; i < options.length; i++){
		var opt = document.createElement('option');
		opt.text = opt.value = options[i];
		os.appendChild(opt);
	}

	os.onchange = updateMenu;

	// Create the second menu
	var os2 = document.createElement('select');
	os2.id = 'os2';
	os2.disabled = true;
	os.parentNode.appendChild(os2);
}
