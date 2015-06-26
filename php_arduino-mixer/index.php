<?php

include('rb.php');
$sqliteSchemeFilePath = getcwd().DIRECTORY_SEPARATOR.'sqlite.scheme.sql';
$sqliteFilePath = getcwd().DIRECTORY_SEPARATOR.'data.s3db';

R::setup('sqlite:'.$sqliteFilePath);

$c = $_GET['c'];
$d = $_GET['d'];
if($c == 'read')
{
	if(!empty($_GET['code']))
	{
		$code = trim($_GET['code']);
		$w = R::findOne('workshop', " code=? ", array($code) );
		if(!empty($w) && !empty($w->code))
		{
			echo "{$w->red},{$w->green},{$w->blue}";
		}
		else
		{
			echo "<p>Invalid code</p>";
		}
	}
	else
	{
		echo "<p>Invalid code</p>";
	}
}
elseif($c == 'write')
{
	$code = trim($_GET['code']);
	if(!empty($code))
	{
		$w = R::findOne('workshop', ' code = ? ',array($code));
		
		if(!empty($w))
		{
			$red = $w->red;
			$green = $w->green;
			$blue = $w->blue;
			
			if($d == "process")
			{
				$red = trim($_POST['red']);
				$green = trim($_POST['green']);
				$blue = trim($_POST['blue']);
				
				if(isset($red) && isset($green) && isset($blue) && is_numeric($red) && is_numeric($green) && is_numeric($blue))
				{
					if($red>255)$red=255;
					if($green>255)$green=255;
					if($blue>255)$blue=255;
					
					if($red<0)$red=0;
					if($green<0)$green=0;
					if($blue<0)$blue=0;
					
					$w->red = (int)$red;
					$w->green = (int)$green;
					$w->blue = (int)$blue;
					$id = R::store($w);
					
					if(!empty($id))
					{
						echo "<p>Write done to account '{$w->code}' with RGB value of ({$red}, {$green}, {$blue}).</p>";
						echo "<p><a href='index.php?c=write&code={$w->code}'>Back to write</a></p>";
					}
					else
					{
						echo "<p>Fail to register '{$code}'. Pls try another code.</p>";
					}
				}
				else
				{
					echo "<p>Invalid RGB value</p>";
				}
			}
			else
			{
				echo "<h2>Welcome back, {$code}</h2>";
				echo '<form action="index.php?c=write&d=process&code='.$code.'" method="post" >';
				echo '<p><label>Red</label> <input type="text" value="'.$red.'" name="red" /> (value from 0-255 only)</p>';
				echo '<p><label>Green</label> <input type="text" value="'.$green.'" name="green" /> (value from 0-255 only)</p>';
				echo '<p><label>Blue</label> <input type="text" value="'.$blue.'" name="blue" /> (value from 0-255 only)</p>';
				echo '<p><input type="submit" value="Write" /></p>';
				echo '</form>';
				
				echo "<p>To read, access here <a href='index.php?c=read&code=$code'>index.php?c=read&code=$code</a></p>";
			}
		}
		else
		{
			echo "<p>Invalid code '{$code}', account not found. Pls register first.</p>";
		}
	}
	else
	{
		echo "<p>Code cannot be empty</p>";
	}
}
elseif($c == 'register')
{
	
	if($d == "process")
	{
		if(!empty($_POST['code']))
		{
			$code = trim($_POST['code']);
			
			$wExists = R::findOne('workshop', ' code = ? ',array($code));
			if(empty($wExists))
			{
				$w = R::dispense('workshop');
				$w->code = $code;
				$w->red = "0";
				$w->green = "0";
				$w->blue = "0";
				$id = R::store($w);
				
				if(!empty($id))
				{
					echo "<p>Registration done. Your code is '{$w->code}'.</p>";
					echo "<p>To write, access here <a href='index.php?c=write&code={$w->code}'>index.php?c=write&code={$w->code}</a>.</p>";
				}
				else
				{
					echo "<p>Fail to register '{$code}'. Pls try another code.</p>";
				}
			}
			else
			{
				echo "<p>Fail to register '{$code}'. Pls try another code.</p>";
			}
		}
		else
		{
			echo "<p>Code cannot be empty</p>";
		}
	}
	else
	{
		echo '<form action="index.php?c=register&d=process" method="post" >';
		echo '<input type="text" value="" name="code" />';
		echo '<input type="submit" value="Register" />';
		echo '</form>';
	}
}
else if($c == 'list')
{
	echo "<p>Listing all registered account:</p>";
	$ws = R::findAll('workshop');
	foreach($ws as $w)
	{
		echo "<p>{$w->code}: R[{$w->red}] G[{$w->green}] B[{$w->blue}]</p>";
	}
}
else if($c == 'reset')
{
	echo "<p>Reset all data</p>";
	R::wipe('workshop');
	echo "<p>DONE</p>";
}
else
{
	echo "<p>Invalid request</p>";
}