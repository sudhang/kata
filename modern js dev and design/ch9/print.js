window.onload = function() {
		'use strict';
		if (typeof window.print == 'function'){
				var printButton = document.createElement('button');

				if (printButton.textContent != 'undefined'){
						printButton.textContent = 'Print';
				} else	{
					printButton.innerText = 'Print';
				}
				printButton.onclick = function (){
					window.print();
				};

				// if this browser supports the print function, insert the print button before the div "main"
				document.body.insertBefore(printButton, document.getElementById('main'));
		}
}

