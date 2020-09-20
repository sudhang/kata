function calculate()	{
  'use strict';
  var volume;
  
  var radius = document.getElementById('radius');
  if (radius && isFinite(radius) radius.value > 0)	{
    volume = ((4/3) * Math.PI * Math.pow(radius.value, 3)).toFixed(4);
  } else {
    volume = 'Please enter a valid radius!';
  }
  document.getElementById('volume').value = volume;
  
  return false;
}

function init() {
  'use strict';
  document.getElementById('calculateForm').onsubmit = calculate;
}

window.onload = init;