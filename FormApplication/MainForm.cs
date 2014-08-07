using System;
using System.Drawing;
using System.Windows.Forms;
using CachedBitmapUtility;

namespace FormApplication {
  public partial class MainForm : Form {
    private UnmanagedCachedBitmap m_CachedBitmap;
    private UnmanagedBitmap m_Bitmap;

    public MainForm() {
      InitializeComponent();

      using (var stream = typeof(MainForm).Assembly.GetManifestResourceStream("FormApplication.character.png")) {
        var bitmap = (Bitmap)Bitmap.FromStream(stream);
        m_Bitmap = UnmanagedBitmap.FromHicon(bitmap.GetHicon());
      }
    }

    protected override void OnPaint(PaintEventArgs e) {
      var graphics = e.Graphics;
      IntPtr hdc = IntPtr.Zero;
      try {
        hdc = graphics.GetHdc();
        using (var unmanagedGraphics = new UnmanagedGraphics(hdc)) {
          if (m_CachedBitmap == null) {
            m_CachedBitmap = new UnmanagedCachedBitmap(m_Bitmap, unmanagedGraphics);
          }
          unmanagedGraphics.DrawCachedBitmap(m_CachedBitmap, 0, 0);
        }
      } finally {
        if (hdc != IntPtr.Zero) {
          graphics.ReleaseHdc(hdc);
        }
      }
    }
  }
}
