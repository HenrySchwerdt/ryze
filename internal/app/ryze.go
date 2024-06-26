package app

import (
	"ryze/internal/ui"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"
)

type RyzeGUI struct {
	app    fyne.App
	window fyne.Window
}

func NewRyzeGUI() *RyzeGUI {
	ryze := &RyzeGUI{}
	ryze.app = app.New()
	ryze.window = ryze.app.NewWindow(app_name)
	ryze.window.SetPadded(false)
	ryze.window.SetContent(ui.NewRContainer())
	return ryze
}

func (r *RyzeGUI) Run() {
	r.window.ShowAndRun()
}
