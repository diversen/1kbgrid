<?php

class layout2 extends layout {

        /**
     * method for parsing a module menu.
     * A module menu is a menu connected to a main menu item.
     *
     * @param   array   menu to parse
     * @return  string  containing menu in html form ul li
     */
    public static function parseModuleMenu($menu, $type){
        $str = '';
        $str.= MENU_LIST_START . "\n";
        $num_items = $ex = count($menu);

        foreach($menu as $k => $v){
            if ( !empty($v['auth'])){
                if (!session::isUser()) continue;
                if (!session::isAdmin() && $v['auth'] == 'admin') continue;
                if (!session::isSuper()  && $v['auth'] == 'super') continue;
            }

            $str .= MENU_SUBLIST_START;
            if ($num_items && ($num_items != $ex) ){
                $str .= MENU_SUB_SEPARATOR;
            }
            $num_items--;



            $str .= create_link($v['url'], $v['title']);
            $str .= MENU_SUBLIST_END;
        }
        $str.= MENU_LIST_END . "\n";
        return $str;
    }
    /**
     * function for parsing MAIN menu list.
     * Main menu is the menu holding all info about modules in database.
     * Therefore it is also some sort of top level module menu.
     */
    public static function parseMainMenuList (){

        $module_frag = uri::$info['module_frag'];
        //print_r(uri::$info);
        $menu = array();
        $menu = self::$menu['main'];
        $str = $css = '';
        foreach($menu as $k => $v){
            if ( !empty($v['auth'])){
                if (!session::isUser()) continue;
                if (!session::isAdmin() && $v['auth'] == 'admin') continue;
                if (!session::isSuper()  && $v['auth'] == 'super') continue;
            }

            //echo $_SERVER['REQUEST_URI'];
            $options = array ();
            //echo $v['url']; die;
            
            // find first part of url
            $url = explode('/', $v['url']);
            if (isset($url[0]) && isset($module_frag)) {
               if ($url[0] == $module_frag) {
                   $options['class'] = 'current';
               } else {
                   //$current = false;
               }
            }

            
            $str.="<li>";
            $link = html::createLink( $v['url'], lang::translate($v['title']), $options);
            $str.=  $link;
            if (isset($v['sub'])){
                $str .= self::parseMainMenuList($v['sub']);
            }
            $str .= "</li>\n";
        }
        return $str;

    }

    /**
     * method for getting main module menu as html
     *
     * @return string containing menu module menu as html
     */
    public static function getMainMenu(){

        $str = '';
        $str.= '<ul>' . "\n";
        $str.= self::parseMainMenuList();
        $str .= "</ul>\n";
        return $str;
    }
}
