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