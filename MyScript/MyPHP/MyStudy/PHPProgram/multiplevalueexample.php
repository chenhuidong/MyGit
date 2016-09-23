<?php
   if (isset($_POST['submit']))
   {
      echo "You like the following languages:<br />";
      foreach($_POST['languages'] AS $language) echo "$language<br />";
   }
?>