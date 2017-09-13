<?php
/**
 * @file
 * feature_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'movie_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'movie search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'movie search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_genre' => 'field_genre',
    'field_imdb_rating' => 'field_imdb_rating',
    'field_plot' => 'field_plot',
    'field_director' => 'field_director',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_genre' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imdb_rating' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_plot' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_director' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Director */
  $handler->display->display_options['fields']['field_director']['id'] = 'field_director';
  $handler->display->display_options['fields']['field_director']['table'] = 'field_data_field_director';
  $handler->display->display_options['fields']['field_director']['field'] = 'field_director';
  $handler->display->display_options['fields']['field_director']['label'] = 'director';
  /* Field: Content: Genre */
  $handler->display->display_options['fields']['field_genre']['id'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['table'] = 'field_data_field_genre';
  $handler->display->display_options['fields']['field_genre']['field'] = 'field_genre';
  $handler->display->display_options['fields']['field_genre']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_genre']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_genre']['delta_offset'] = '0';
  /* Field: Content: Imdb Rating */
  $handler->display->display_options['fields']['field_imdb_rating']['id'] = 'field_imdb_rating';
  $handler->display->display_options['fields']['field_imdb_rating']['table'] = 'field_data_field_imdb_rating';
  $handler->display->display_options['fields']['field_imdb_rating']['field'] = 'field_imdb_rating';
  $handler->display->display_options['fields']['field_imdb_rating']['label'] = 'Rating';
  $handler->display->display_options['fields']['field_imdb_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imdb_rating']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Plot */
  $handler->display->display_options['fields']['field_plot']['id'] = 'field_plot';
  $handler->display->display_options['fields']['field_plot']['table'] = 'field_data_field_plot';
  $handler->display->display_options['fields']['field_plot']['field'] = 'field_plot';
  $handler->display->display_options['fields']['field_plot']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_plot']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'movie' => 'movie',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_director' => 'field_director',
    'field_plot' => 'field_plot',
  );
  /* Filter criterion: Content: Genre (field_genre) */
  $handler->display->display_options['filters']['field_genre_tid']['id'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['table'] = 'field_data_field_genre';
  $handler->display->display_options['filters']['field_genre_tid']['field'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_genre_tid']['expose']['operator_id'] = 'field_genre_tid_op';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['operator'] = 'field_genre_tid_op';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['identifier'] = 'field_genre_tid';
  $handler->display->display_options['filters']['field_genre_tid']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['field_genre_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_genre_tid']['vocabulary'] = 'genre';
  /* Filter criterion: Content: Language (field_language) */
  $handler->display->display_options['filters']['field_language_tid']['id'] = 'field_language_tid';
  $handler->display->display_options['filters']['field_language_tid']['table'] = 'field_data_field_language';
  $handler->display->display_options['filters']['field_language_tid']['field'] = 'field_language_tid';
  $handler->display->display_options['filters']['field_language_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_language_tid']['expose']['operator_id'] = 'field_language_tid_op';
  $handler->display->display_options['filters']['field_language_tid']['expose']['operator'] = 'field_language_tid_op';
  $handler->display->display_options['filters']['field_language_tid']['expose']['identifier'] = 'field_language_tid';
  $handler->display->display_options['filters']['field_language_tid']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['field_language_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_language_tid']['vocabulary'] = 'language';
  /* Filter criterion: Content: Year (field_year) */
  $handler->display->display_options['filters']['field_year_tid']['id'] = 'field_year_tid';
  $handler->display->display_options['filters']['field_year_tid']['table'] = 'field_data_field_year';
  $handler->display->display_options['filters']['field_year_tid']['field'] = 'field_year_tid';
  $handler->display->display_options['filters']['field_year_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_year_tid']['expose']['operator_id'] = 'field_year_tid_op';
  $handler->display->display_options['filters']['field_year_tid']['expose']['operator'] = 'field_year_tid_op';
  $handler->display->display_options['filters']['field_year_tid']['expose']['identifier'] = 'field_year_tid';
  $handler->display->display_options['filters']['field_year_tid']['expose']['remember_roles'] = array(
    2 => '2',
    11 => 0,
    6 => 0,
    5 => 0,
    3 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['field_year_tid']['group_info']['identifier'] = 'field_year_tid';
  $handler->display->display_options['filters']['field_year_tid']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
    2 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );
  $handler->display->display_options['filters']['field_year_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_year_tid']['vocabulary'] = 'year';
  /* Filter criterion: Content: Imdb Rating (field_imdb_rating) */
  $handler->display->display_options['filters']['field_imdb_rating_value']['id'] = 'field_imdb_rating_value';
  $handler->display->display_options['filters']['field_imdb_rating_value']['table'] = 'field_data_field_imdb_rating';
  $handler->display->display_options['filters']['field_imdb_rating_value']['field'] = 'field_imdb_rating_value';
  $handler->display->display_options['filters']['field_imdb_rating_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imdb_rating_value']['expose']['operator_id'] = 'field_imdb_rating_value_op';
  $handler->display->display_options['filters']['field_imdb_rating_value']['expose']['label'] = 'Imdb Rating (field_imdb_rating)';
  $handler->display->display_options['filters']['field_imdb_rating_value']['expose']['operator'] = 'field_imdb_rating_value_op';
  $handler->display->display_options['filters']['field_imdb_rating_value']['expose']['identifier'] = 'field_imdb_rating_value';
  $handler->display->display_options['filters']['field_imdb_rating_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_imdb_rating_value']['group_info']['identifier'] = 'field_imdb_rating_value';
  $handler->display->display_options['filters']['field_imdb_rating_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '<5',
      'operator' => '<',
      'value' => array(
        'value' => '5',
        'min' => '',
        'max' => '5',
      ),
    ),
    2 => array(
      'title' => '5-7.5',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '5',
        'max' => '7.5',
      ),
    ),
    3 => array(
      'title' => '7.5-9',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '7.5',
        'max' => '9',
      ),
    ),
    4 => array(
      'title' => '>9',
      'operator' => '>',
      'value' => array(
        'value' => '9',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'movie-search';
  $export['movie_search'] = $view;

  return $export;
}
