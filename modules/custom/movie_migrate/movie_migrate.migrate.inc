<?php
/*
 * Extending Migration class to Movie_Migration class.
*/
abstract class Movie_Migration extends Migration {
  // A Migration constructor takes an array of arguments as its first parameter.
  // The arguments must be passed through to the parent constructor.
  public function __construct($arguments) {
    //parent constructor call
    parent::__construct($arguments);
    $this->description = t('Migrate JSON Movie Data to Drupal7.');
    //List of fields from JSON
    $fields = array(
      'plot' => 'A summary of the movie',
      'rated' => 'Movie ratings',
      'language' => 'Movie Language',
      'title' => 'Title of the movie',
      'country' => 'Movie Country',
      'writer' => 'Movie Writer',
      'year' => 'Movie year',
      'metascore' => 'Movie metascore',
      'imdb_id' => 'Movie IMDB ID',
      'director' => 'Movie director',
      'released' => 'Released date',
      'imdb_rating' => 'IMDB Ratings',
      'awards' => 'Movie awards',
      'poster' => 'Poster URL',
      'genre' => 'Movie genre',
      'actors' => 'Actors in the movie',
      'runtime' => 'Duration of the movie',
      'type' => 'Type of the movie',
      'response' => 'Response',
      'imdb_votes' => 'Total IMDB votes',
    );
    //Source JSON file
    $json_file =  'https://gist.githubusercontent.com/kasisnu/3022b00aead25810b794/raw/05d573ac97071e34b0ee89c2ee4470dc9042b016/use_the_force.json';
    $this->source = new MigrateSourceJSON($json_file, 'imdb_id', $fields);
    //Destination to node - content type - movie
    $this->destination = new MigrateDestinationNode('movie');
    //MigrateSQLMap primary key as imdb_id
    $this->map = new MigrateSQLMap(
                  $this->machineName,
                    array(
                      'imdb_id' => array(
                      'type' => 'varchar',
                      'length' => 255,
                      'not null' => TRUE,
                      ),
                    ),
                    MigrateDestinationNode::getKeySchema()
                  );
		//Field mappings
    $this->addFieldMapping('field_plot', 'plot');
    $this->addFieldMapping('field_rated', 'rated');

    $this->addFieldMapping('field_language', 'language')->separator(',');
    $this->addFieldMapping('field_language:create_term') ->defaultValue(TRUE);
    $this->addFieldMapping('field_language:ignore_case')->defaultValue(TRUE);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_country', 'country') ->separator(',');
    $this->addFieldMapping('field_country:create_term') ->defaultValue(TRUE);
    $this->addFieldMapping('field_country:ignore_case')->defaultValue(TRUE);

    $this->addFieldMapping('field_writer', 'writer');

    $this->addFieldMapping('field_year', 'year');
    $this->addFieldMapping('field_year:create_term') ->defaultValue(TRUE);

    $this->addFieldMapping('field_metascore', 'metascore');
    $this->addFieldMapping('field_imdb_id', 'imdb_id');

    $this->addFieldMapping('field_director', 'director');

    $this->addFieldMapping('field_released_date', 'released');
    $this->addFieldMapping('field_imdb_rating', 'imdb_rating');
    $this->addFieldMapping('field_awards', 'awards');
    $this->addFieldMapping('field_poster', 'poster');

    $this->addFieldMapping('field_genre', 'genre') ->separator(',');
    $this->addFieldMapping('field_genre:create_term') ->defaultValue(TRUE);
    $this->addFieldMapping('field_genre:ignore_case')->defaultValue(TRUE);

    $this->addFieldMapping('field_actors', 'actors') ->separator(',');
    $this->addFieldMapping('field_actors:create_term') ->defaultValue(TRUE);
    $this->addFieldMapping('field_actors:ignore_case')->defaultValue(TRUE);

    $this->addFieldMapping('field_runtime', 'runtime');
    $this->addFieldMapping('field_type', 'type');
    $this->addFieldMapping('field_response', 'response');
    $this->addFieldMapping('field_imdb_votes', 'imdb_votes');
  }
}

/*
 * Extending Movie_Migration class to MigrateMovieMigration
 * class.
*/
class MigrateMovieMigration extends Movie_Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
	}
}

/*
 * Required - tells the Migrate module that you are implementing version 2
 * of the Migrate API.
*/
function movie_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'json_migration' => array(
        'title' => t('JSON Migrations'),
      ),
    ),
    'migrations' => array(
      'Movies' => array(
        'class_name' => 'MigrateMovieMigration',
        'group_name' => 'json_migration',
      ),
    ),
  );
  return $api;
}
