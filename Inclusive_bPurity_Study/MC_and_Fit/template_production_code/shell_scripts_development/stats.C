{
//========= Macro generated from object: stats/A special TPaveText to draw histogram statistics.
//========= by ROOT version6.08/02
   
   TPaveStats *ptstats = new TPaveStats(0.475104,0.479626,0.67553,0.638436,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("Hpt_rel_gen");
   AText->SetTextSize(0.0365262);
   AText = ptstats->AddText("Entries = 9040   ");
   AText = ptstats->AddText("Mean  = 0.8734");
   AText = ptstats->AddText("Std Dev   = 0.5009");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
}
