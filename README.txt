// $Id$

Plings
------

Plings is a source of information about brilliant, inspiring places to go and
stuff to do for everyone aged 13-19. For more information about Plings see
http://plings.net

This module provides support for querying the Plings API and displaying the
returned activities in a users area. It provides a default View that has a
block and a page display that can be configured further.



Getting a Plings API key
------------------------
Plings will not work without an API key, for more information on how to obtain
one see http://www.plings.info/wiki/index.php/API_Keys#Register_for_a_Key



Supported methods of detecting user location
--------------------------------------------
There are many ways to capture information about the location of a user in
Drupal, Plings needs to know how your site does it! Currently the following
methods are supported:

  * location, location_user module - http://drupal.org/project/location



Requires
--------
Plings requires the following additional contributed modules:

  * views - http://drupal.org/project/views

NB. location, location_user are not dependencies but are currently the only
supported methods of detecting user location.

Plings relies on cron - for more information about setting up and/or running
cron see - http://drupal.org/getting-started/6/install/cron


Installation
------------
Place the plings directory in your sites modules directory - usually this is
located at sites/all/modules.
Go to Administer -> Site building -> Modules and find Plings in the list of
modules.
Tick the checkbox next to Plings and click the Save configuration button.



Configuration
-------------
Go to Administer -> Site configuration -> Plings.
Enter your Plings API key.
Select a Limit - this value is the maximum number of Plings that will be
returned when a call is made to the Plings API.
Select a Period - this is the period of Plings that will be returned from the
Plings API and represents days:
  0 = Today
  1 = Today and tomorrow
  2 = Today, tomorrow and the day after
  ...
  7 = The coming week.

Select the User location detection method.
Click Save configuration.
Select the Filter type - whether to filter by town or postcode.
Click Save configuration.
Go to Administer -> Reports -> Status report and click on the run cron
manually link.
Go to Administer -> Site building -> Views and enable the Plings default view.
Go to Administer -> Site building -> Blocks and enable the plings: Block.



Uninstalling
------------
Go to Administer -> Site building -> Modules and find Plings in the list of
modules.
Make sure the checkbox next to Plings is unticked and click the Save
configuration button - this effectively disables the Plings module but will not
remove your settings and will not remove the Plings database tables.
To fully uninstall Plings, you will need to take the extra steps of clicking
the Uninstall tab (on the same page, Administer -> Site building -> Modules),
ensure the checkbox next to Plings is ticked then click the Uninstall button.
Confirm you wish to continue uninstalling Plings when prompted.