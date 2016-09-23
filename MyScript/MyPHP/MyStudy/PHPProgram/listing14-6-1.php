<?php
   /* Because the authentication prompt needs to be invoked twice,
      embed it within a function.
   */
   function authenticate_user() {
      header('WWW-Authenticate: Basic realm="Secret Stash"');
      header("HTTP/1.0 401 Unauthorized");
      exit;
   }

   /* If $_SERVER['PHP_AUTH_USER'] is blank, the user has not yet been prompted for
      the authentication information.
   */
   if (! isset($_SERVER['PHP_AUTH_USER'])) {
      authenticate_user();
   } else {
      // Connect to the MySQL database
         $conn = mysqli_connect("localhost", "chenhuidong", "Chenhd@443420");

         $db = mysqli_select_db($conn, "public");

      // Create and execute the selection query.
      $query = "SELECT username, pswd FROM logins
                WHERE username='$_SERVER[PHP_AUTH_USER]' AND  
                pswd=md5('$_SERVER[PHP_AUTH_PW]')";

      $result = mysqli_query($conn, $query);

      if (!$result) {
         printf("Error: %s\n", mysqli_error($conn));
         exit();
      }

      // If nothing was found, reprompt the user for the login information.
      if (mysqli_num_rows($result) == 0) {
         authenticate_user();
      }
      else {
         echo "Welcome to the secret archive!";
      }
   }
?>
