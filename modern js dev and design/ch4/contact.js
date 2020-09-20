function process() {
  'use strict';
  var okay = true;
  
  var email = document.getElementById('email');
  var comments = document.getElementById('comments');
  
  if (!email || !email.value || (email.value.length < 6) || (email.value.indexOf('@') == -1)) {
    okay = false;
    alert('Please enter a valid email address');
  }
  
  if (!comments || !comments.value || (comments.value.indexOf('<') != -1))	{
    okay = false;
    alert('Please enter comments without any html');
  }
  
  return okay;
}

function init() {
  'use strict';
  document.getElementById('theForm').onsubmit = process;
}

window.onload = init;