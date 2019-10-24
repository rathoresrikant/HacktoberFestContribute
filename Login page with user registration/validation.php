<?php
session_start();

$con = mysqli_connect('localhost','root','');
mysqli_select_db($con, 'userregistration');
$name = $_POST['user'];
$pass = $_POST['password'];
$s = "select *from usertable where name ='$name' && password='$pass'";
$result = mysqli_query($con ,$s);
$num = mysqli_num_rows($result);
if($num ==1)
{
	$_SESSION['username']=$name;
	header('location:home.php');
	
}
else{
	header('location:login.php');

 
 }
?>