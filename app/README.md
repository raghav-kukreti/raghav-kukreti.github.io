 This is my entry for the website design competiton conducted by Camp K12.
 I have chosen the topic : __Yo Yo Money Singh__
 
 1. Overview
 2. Features
 3. Languages Used
 4. Detailed Inspection
 5. Miscellaneous Aspects
 
 ## Overview
I chose Yo Yo Money Singh as my topic because it was the only one which was out of the box. I have gone for a minimalist theme with dark, cool colours. Primary colour is light blue -> `rgba(81, 187, 255, 1)` and the background is black -> `#040404`

##Features
1. Animated scroll
2. Custom Scrollbar
3. Animated menu
4. Fully functional music player.
5. Blog with one page
6. Mock form interactions.
7. *Bonus*
	* Custom album art
	* Custom persona of Money Singh 

 ## Languages Used
 I have used HTML5, CSS3 and jQuery. I wrote the HTML markup from scratch but for the CSS and JavaScript I used preprocessors. CSS was compiled from Sass and the jQuery from Coffeescript.
 All of this was done through the magic of Prepros.

 ## Detailed Inspection
I first sketched out the basic idea on a sheet of paper and built the first version on top of that. It went through a lot of versions and style changes. Let's start with the markup.

 #### HTML
 The HTML is pretty straight forward and having commented heavily, the markup would be easy to read.

 #### CSS
 CSS was compiled through SASS (The libsass compiler was used). It first goes through the whole process of normalizing the website (Using [normalize.css](http://necolas.github.io/normalize.css/)) and then the main styles come into play. The variables have been defined at the top of the stylesheet and have been used throughout the web page. 

 #### JavaScript
 The JavaScript is written by me expect for the smoothscroll script. Which starts on `line 295` of the index.html.
 There are few parts to the JavaScript.
 One is the Menu Bar functionality, the Music player and the onscroll animation.
 ##### Menu
 The menu first sets the menu visibility to false as a variable. Then it adds CSS styles to the `li` ie, `animation-delay`.
 Then, it listens for the `onClick()` event on the menu button and when clicked it gives it the CSS style of `left:0px;` else, it gives it the default position which is `-200px.`
 ##### Music Player
 The music player was just a simple idea to provide a sample of Money's songs but it is an integral part of the website.
 The music player too works on the system of heights and background positions. 

 ## Miscellaneous
 I have made six album covers and included the PSD for the same.
 They have been used in the website.

 Running the website on a server such as that of [Prepros](http://www.alphapixels.com/prepros) is appreciated to provide the best experience but viewing it by double clicking is fine too. 
