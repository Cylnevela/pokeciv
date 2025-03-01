# This project extends the project agneraylafage


# REQUIREMENTS

## SFML

The project first requires SFML for everything link with rendering. I downloaded it here : 
https://www.sfml-dev.org/download/sfml/2.5.1/

## LIBMICROHTTPD

As we use libmicrohttpd, libmicrohttpd may not be found.
In this case, specify the directory where the .lib file is located with the PATHS argument in the command find_library.

# CONFIGURATION

First you need to configure the project. 
At the root project level use the command
    cmake .

The terminal must say that it found SFML and display its version and directory. 
For example :
    -- Found SFML 2.5.1 in D:/Utils/SFML-2.5.1/lib/cmake/SFML
    -- Configuring done

If libmicrohttpd is found correctly, theses lines are followed by :
    -- Generating done

And then by :
    -- Build files have been written to: %YOUR_DIRECTORY%

# Then 
