function formatName()	{
  'use strict';
  var formattedName = '';
  
  var firstName = document.getElementById('firstName').value;
  var lastName = document.getElementById('lastName').value;
  formattedName = firstName + ' ' + lastName;
  document.getElementById('formattedName').value = formattedName;
  return false;
}

function init()	{
  'use strict';
  document.getElementById('nameForm').onsubmit = formatName;
}

window.onload = init;