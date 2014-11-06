	// menu button funtionality
	var menuVis = false;

	$('#nav-inner li').each(function(i) {
	    $(this).css({
	        transitionDelay: i / 20 + 's',
	        webkitTransitionDelay: i / 20 + 's'
	    });
	    //console.log(i);
	});

	$('#menu-btn').on('click', function() {
	    if (!menuVis) {
	        $('#nav-inner li').each(function(i) {
	            $(this).css({
	                left: 0 + 'px'
	            }, 20);
	        });
	        menuVis = true;
	    } else {
	        $('#nav-inner li').each(function(i) {
	            $(this).css({
	                left: -200 + 'px'
	            });
	        });
	        menuVis = false;
	    }
	});

	$('#nav-inner li').each(function() {
	    var menu_li_link = $(this).data('link');
	    $(this).on('click', function() {
	        // console.log(menu_li_link + ',' + $('#'+menu_li_link).offset().top);
	        $('body').scrollTo($('#' + menu_li_link).offset().top, 2000, 'easeOut');
	    });
	});

	// is player visible ?
	$('#music-player-wrapper #heading-wrapper').on('click', function() {
	    if ($(this).hasClass('invisible')) {
	        $('#music-player-wrapper').css('height', '240px');
	        $(this).css({
	            backgroundPosition: 'right -46px'
	        });
	        $(this).removeClass('invisible');
	    } else {
	        $('#music-player-wrapper').css('height', '35px');
	        $(this).css({
	            backgroundPosition: 'right -4px'
	        });
	        $(this).addClass('invisible');
	    }
	});

	// music functionality
	var audio = new Audio();
	audio.src = $('#music-wrapper li.current').data('src');
	audio.controls = false;
	audio.loop = false;
	audio.autoplay = false;

	$('#music-wrapper li').each(function() {
	    $(this).on('click', function() {
	        $('.current').removeClass('current');
	        $(this).addClass('current');
	        $('#song-name').html($(this).html());
	        stopMusic();
	        audio.src = $(this).data('src');
	        audio.load();
	        playMusic();
	    });
	});

	function playMusic() {
	    audio.play();
	    $('.music-buttons#play').css({
	        background: 'url(\'images/music-controls.png\') -16px -21px no-repeat'
	    });
	    console.log(audio.src);
	    $('.music-buttons#play').removeClass('play');
	}

	function pauseMusic() {
	    audio.pause();
	    $('.music-buttons#play').css({
	        background: 'url(\'images/music-controls.png\') 6px -21px no-repeat'
	    });
	    $('.music-buttons#play').addClass('play');
	}

	function stopMusic() {
	    audio.pause();
	    audio.currentTime = 0;
	}

	$('.music-buttons#play').on('click', function() {
	    if ($(this).hasClass('play')) {
	        playMusic();
	    } else {
	        pauseMusic();
	    }
	});

	$('.music-buttons#stop').on('click', function() {
	    stopMusic();
	    $('.music-buttons#play').addClass('play').css({
	        background: 'url(\'images/music-controls.png\') 6px -21px no-repeat'
	    });
	});
