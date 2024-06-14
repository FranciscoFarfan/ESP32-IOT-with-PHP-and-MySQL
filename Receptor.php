<?php
    if($_POST['confirm']==1){
        echo "Su mensaje fue:".$_POST['texto']." y el estado fue: ".$_POST['estado'];
        
    }else{
        echo "acceso incorrecto";//No se conecto desde una maquina o desde POST
    }
        
?>

  