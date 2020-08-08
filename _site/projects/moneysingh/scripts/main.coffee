# menu button funtionality

#console.log(i);

# console.log(menu_li_link + ',' + $('#'+menu_li_link).offset().top);

# is player visible ?

# music functionality
playMusic = ->
  audio.play()
  $(".music-buttons#play").css background: "url('images/music-controls.png') -16px -21px no-repeat"
  console.log audio.src
  $(".music-buttons#play").removeClass "play"
  return
pauseMusic = ->
  audio.pause()
  $(".music-buttons#play").css background: "url('images/music-controls.png') 6px -21px no-repeat"
  $(".music-buttons#play").addClass "play"
  return
stopMusic = ->
  audio.pause()
  audio.currentTime = 0
  return
menuVis = false
$("#nav-inner li").each (i) ->
  $(this).css
    transitionDelay: i / 20 + "s"
    webkitTransitionDelay: i / 20 + "s"

  return

$("#menu-btn").on "click", ->
  unless menuVis
    $("#nav-inner li").each (i) ->
      $(this).css
        left: 0 + "px"
      , 20
      return

    menuVis = true
  else
    $("#nav-inner li").each (i) ->
      $(this).css left: -200 + "px"
      return

    menuVis = false
  return

$("#nav-inner li").each ->
  menu_li_link = $(this).data("link")
  $(this).on "click", ->
    $("body").scrollTo $("#" + menu_li_link).offset().top, 2000, "easeOut"
    return

  return

$("#music-player-wrapper #heading-wrapper").on "click", ->
  if $(this).hasClass("invisible")
    $("#music-player-wrapper").css "height", "240px"
    $(this).css backgroundPosition: "right -46px"
    $(this).removeClass "invisible"
  else
    $("#music-player-wrapper").css "height", "35px"
    $(this).css backgroundPosition: "right -4px"
    $(this).addClass "invisible"
  return

audio = new Audio()
audio.src = $("#music-wrapper li.current").data("src")
audio.controls = false
audio.loop = false
audio.autoplay = false
$("#music-wrapper li").each ->
  $(this).on "click", ->
    $(".current").removeClass "current"
    $(this).addClass "current"
    $("#song-name").html $(this).html()
    stopMusic()
    audio.src = $(this).data("src")
    audio.load()
    playMusic()
    return

  return

$(".music-buttons#play").on "click", ->
  if $(this).hasClass("play")
    playMusic()
  else
    pauseMusic()
  return

$(".music-buttons#stop").on "click", ->
  stopMusic()
  $(".music-buttons#play").addClass("play").css background: "url('images/music-controls.png') 6px -21px no-repeat"
  return
