import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { NotFoundComponent } from './not-found/not-found.component';

const routes: Routes = [
  { path: 'add-team', loadChildren: () => import('./team/team.module').then(m => m.TeamModule) },
  { path: 'show-teams', loadChildren: () => import('./team/team.module').then(m => m.TeamModule) },
  { path: 'my-teams', loadChildren: () => import('./team/team.module').then(m => m.TeamModule) },
  { path: '', redirectTo: 'show-teams', pathMatch: 'full' },
  { path: '**', component: NotFoundComponent },
  
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule],
})
export class AppRoutingModule {}