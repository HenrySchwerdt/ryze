package widgets

import (
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/widget"
)

type statusBarBuilder struct {
	background color.Color
}

func NewStatusBar() *statusBarBuilder {
	return &statusBarBuilder{
		background: color.RGBA{R: 0x00, G: 0x00, B: 0x00, A: 0xff},
	}
}

func (s *statusBarBuilder) Background(c color.Color) *statusBarBuilder {
	s.background = c
	return s
}

func (s *statusBarBuilder) Build() *StatusBar {
	return &StatusBar{
		background: s.background,
	}
}

type StatusBar struct {
	widget.BaseWidget
	background color.Color
}

var _ fyne.CanvasObject = (*StatusBar)(nil)

func (s *StatusBar) CreateRenderer() fyne.WidgetRenderer {
	s.ExtendBaseWidget(s)
	bar := canvas.NewRectangle(s.background)
	return &statusBarRenderer{
		statusBar: s,
		bar:       bar,
	}
}

var _ fyne.WidgetRenderer = (*statusBarRenderer)(nil)

type statusBarRenderer struct {
	statusBar *StatusBar
	bar       *canvas.Rectangle
}

func (s *statusBarRenderer) MinSize() fyne.Size {
	return fyne.NewSize(0, 20)
}

func (*statusBarRenderer) Destroy() {
}

func (r *statusBarRenderer) Layout(s fyne.Size) {
	r.bar.Resize(s)
}

func (r *statusBarRenderer) Objects() []fyne.CanvasObject {
	return []fyne.CanvasObject{r.bar}
}

func (r *statusBarRenderer) Refresh() {
	r.bar.FillColor = r.statusBar.background
	r.bar.Refresh()
}
