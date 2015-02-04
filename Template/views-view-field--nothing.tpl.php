<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$field_date = $row->_field_data['nid']['entity']->field_facebook_created_date['und'][0]['value'];

$field_date = strtotime($field_date);
$field_date = date("M jS Y @ g:ia", $field_date);

$objectid = $row->_field_data['nid']['entity']->field_facebook_object_id['und'][0]['value'];
$picture = $row->_field_data['nid']['entity']->field_facebook_pictures['und'][0]['value'];

//var_dump($row->_field_data['nid']['entity']->field_facebook_id['und'][0]['value']);

if(isset($picture)) {
	$url = "https://graph.facebook.com/".$objectid."/picture";
	$size = getimagesize($url);
	if($size) {
		 $thePicture = '<div class="facebook-post-image"><a href="'.$url.'" target="_blank"><img src="'.$url.'"></a></div>';
	} else {
		 $thePicture = '<div class="facebook-post-image"><a href="'.$picture.'" target="_blank"><img src="'.$picture.'"></a></div>';
	}
}
$screenName = $row->_field_data['nid']['entity']->field_facebook_screen_name['und'][0]['value'];
$message = $row->_field_data['nid']['entity']->field_facebook_message['und'][0]['value'];
$link = $row->_field_data['nid']['entity']->field_facebook_link['und'][0]['value'];


//function twitterify($ret) {
  $message = preg_replace("#(^|[\n ])([\w]+?://[\w]+[^ \"\n\r\t< ]*)#", "\\1<a href=\"\\2\" target=\"_blank\">\\2", $message);
  $message = preg_replace("#(^|[\n ])((www|ftp)\.[^ \"\t\n\r< ]*)#", "\\1<a href=\"http://\\2\" target=\"_blank\">\\2", $message);
  $message = preg_replace("/@(\w+)/", "<a class=\"hashtag\" href=\"http://www.twitter.com/\\1\" target=\"_blank\">@\\1</a>", $message);
  $message = preg_replace("/#(\w+)/", "<a class=\"hashtag\" href=\"http://search.twitter.com/search?q=\\1\" target=\"_blank\">#\\1</a>", $message);
//return $ret;
//}
//$message = twitterify($message);



?>
<div class="facebook-contain">
	<div class="facebook-header">
	<div class="facebook-user-name"><a class="facebook-link" target="_blank"  href="https://www.facebook.com/CSofSWIdaho">Crime Stoppers<!--<?php print $screenName; ?>--></a></div><div class="facebook-created">- <?php print $field_date; ?></div></div><!-- /facebook-header -->
	<div class="facebook-body"><?php print $message; ?></div>
	<?php if(isset($thePicture)) { print $thePicture; } ?>
<!--	<div class="facebook-post-image"><a href="<?php print $link; ?>" target="_blank"><img src="<?php print $thePicture; ?>"></a></div> -->

</div><!-- /facebook-contain -->

<?php //print $output; ?><?php

?>