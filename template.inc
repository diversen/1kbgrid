<?php

include_once "layout2.php";

template::init('1kbgrid');



class mainTemplate extends template {


/**
 * method for printing out template header
 *
 * @param  array    assoc array containing current page info
 */
public static function printHeader(){ 

    ?>
<!doctype html>
<html lang="<?=config::$vars['coscms_main']['lang']?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo template::getTitle(); ?></title>


    
<?php

template_assets::setRelAsset('css', 'http://ajax.googleapis.com/ajax/libs/jqueryui/1.10.2/themes/smoothness/jquery-ui.min.css');  
template_assets::setRelAsset('js', 'http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js');  
template_assets::setRelAsset('js', 'http://ajax.googleapis.com/ajax/libs/jqueryui/1.10.2/jquery-ui.min.js');

echo template_assets::getRelAssets();
echo template_assets::getJsHead();
echo template_meta::getMeta();

template::setTemplateCss('1kbgrid', null, 10);
template::setCss('/templates/1kbgrid/grid.css');

echo template_favicon::getFaviconHTML();
echo template_assets::getCompressedCss();
echo template_assets::getInlineCss();




?>


</head>
<body>
<?=template::geStartHTML()?> 

<div id ="page">
<?php

if (session::isAdmin()) { ?>
    <div class="row">
            <div class="column grid_12">

            <?php
$blocks = layout2::getBlock('blocks_top');
                foreach ($blocks as $key => $val){
                    echo $val;
                }

?>

                        
           </div>

    </div>
<?php } ?>
<div class="row">
	<div class="column grid_12">
<?=template::getLogoHTML(); ?>
        </div>
</div>

<div class="row">
	<div class="column grid_12">
            <div id="main_menu">
            <?php
                echo layout2::getMainMenu(); ?>
            </div>
        </div>
</div>

<div class="row">
    <div class="column grid_3">
            <div id="sidebar_left">
            <?php

            $blocks = layout2::getBlock('blocks');
            foreach ($blocks as $key => $val){
                print $val;
            }

            ?>
            </div>
     </div>

     <div class="column grid_9">
         <div id="module_menu"><?php
           echo layout2::getModuleMenu(); ?>
         </div>

         <div class="system_message">
        <?php

        echo session::getActionMessage();

        ?>
        </div>
         <div id="content">


<?php

// end of function

}

/**
 * method for print footer of page
 */
public static function printFooter(){ ?>
         </div>
     </div>	
</div>

<div class="row">
	<div class="column grid_12">&nbsp;
        <?=template::getEndContent()?>
        </div>
</div>
    
</div>
    
        <?php



echo template::getEndHTML();
echo template_assets::getCompressedJs();
echo template_assets::getInlineJs();
?>
</body>
</html>

<? 

    // end function

    }
    
// end class
}

