import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';

import { TeamRoutingModule } from './team-routing.module';
import { TeamsComponent } from './teams/teams.component';
import { TeamComponent } from './team/team.component';
import { FormTeamComponent } from './form-team/form-team.component';
import { MyTeamsComponent } from './my-teams/my-teams.component';


@NgModule({
  declarations: [
    TeamsComponent,
    TeamComponent,
    FormTeamComponent,
    MyTeamsComponent
  ],
  imports: [
    CommonModule,
    TeamRoutingModule
  ]
})
export class TeamModule { }