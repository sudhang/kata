function limitText()	{
  'use strict';
  var limitedText;
  
  var originalText = document.getElementById('comments').value;
  var lastSpace = originalText.lastIndexOf(' ', 100);
  limitedText = originalText.slice(0, lastSpace);
  document.getElementById('count').value = limitedText.length;
  document.getElementById('result').value = limitedText;
  return false;
}

function init()	{
  'use strict';
  document.getElementById('commentForm').onsubmit = limitText;
}

window.onload = init;