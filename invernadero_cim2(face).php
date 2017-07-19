<?php
    echo "recibiendo datos";
    define('MYSQL_HOST'    , 'localhost'     );
    define('MYSQL_DBNAME'  , 'arduinoG10' );
    define('MYSQL_USUARIO' , 'arduinoG10'       );
    define('MYSQL_PASSWORD', '1234qwer'    );
    if( isset($_GET["sh1"], $_GET["sh2"], $_GET["temperatura_ambiente"], $_GET["humedad_ambiente"]) )
    {
        date_default_timezone_set('America/Santiago');
        try
        {
            $conexion = new PDO("mysql:host=" . MYSQL_HOST . ";dbname=" . MYSQL_DBNAME, MYSQL_USUARIO, MYSQL_PASSWORD);
            $stmt = $conexion->prepare("INSERT INTO invernadero1(datetime, sh1, sh2, temperatura_ambiente, humedad_ambiente) VALUES (?,?);");
            $stmt->bindParam(1, date('Y/m/d H:i:s', time()) );
            $stmt->bindParam(2, $_GET["sh1"] );
            $stmt->bindParam(3, $_GET["sh2"] );
            $stmt->bindParam(4, $_GET["temperatura_ambiente"] );
            $stmt->bindParam(5, $_GET["humedad_ambiente"] );
            echo $stmt->execute() ? $conexion->lastInsertId() : -1;
            $conexion = null;
        }
        catch( Exception $e )
        {
            if( $conexion != null )
                $conexion = null;
            echo $e->getMessage();
        }
    }
?>